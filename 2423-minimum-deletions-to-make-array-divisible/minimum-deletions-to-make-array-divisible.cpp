class Solution {
public:
    bool check(int n, vector<int>& v){
        for(auto it: v){
            if(it%n!=0){
                return false;
            }
        }
        return true;
    }

    int minOperations(vector<int>& nums, vector<int>& divide) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        set<int>st;
        map<int,int>mp;
        for(auto it: nums){
            st.insert(it);
            mp[it]++;
        }
        int cnt=0;

        for(auto it: st){
            if(check(it, divide)){
                return cnt;
            }
            cnt+=mp[it];
        }
        return -1;
    }
};