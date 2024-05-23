class Solution {
public:
    int m=1e9+7;
    int rev(int n){
        string s=to_string(n);
        reverse(s.begin(), s.end());
        int num=stoi(s);
        return num;
    }

    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=0;

        for(int i=0;i<n;i++){
            int diff=nums[i]-rev(nums[i]);
            if(mp.find(diff)!=mp.end()){
                ans=(ans%m + mp[diff]%m) %m;
            }
            mp[diff]++;
        }

        return ans;
    }
};