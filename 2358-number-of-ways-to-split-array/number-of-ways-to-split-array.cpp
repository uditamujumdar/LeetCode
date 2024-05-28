class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }

        int ans=0;
        for(int i=0;i<n-1;i++){
            long long s1=pref[i];
            long long s2=pref[n-1]-pref[i];
            if(s1>=s2){
                ans++;
            }
        }
        return ans;
    }
};