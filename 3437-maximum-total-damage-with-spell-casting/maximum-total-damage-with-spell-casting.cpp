class Solution {
public:
    bool check(long long mid, vector<pair<long long, long long>>& power, int i) {
        if (mid < power.size() && power[mid].first - power[i].first > 2)
            return true;
        return false;
    }

    long long solve(int i, vector<pair<long long, long long>>& power, unordered_map<long long, long long>& dp) {
        if(i == power.size()) return 0;
        if(dp.find(i) != dp.end()) return dp[i];

        long long pick = 0;
        long long low = i + 1, high = power.size() - 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, power, i)) high = mid - 1;
            else low = mid + 1;
        }
        pick = power[i].first * power[i].second + solve(low, power, dp);
        long long notPick = solve(i + 1, power, dp);
        dp[i] = max(pick, notPick);
        return dp[i];
    }

    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> mp;
        for (auto val : power) mp[val]++;
        vector<pair<long long, long long>> v;
        for (auto val : mp) v.push_back({ val.first, val.second });
        unordered_map<long long, long long> dp;
        return solve(0, v, dp);
    }
};