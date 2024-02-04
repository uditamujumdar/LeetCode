class Solution {
public:
    long long max(long long a, long long b){
        return a>b ? a:b;
    }

    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans=INT_MIN;
        long long sum=0;
        unordered_map<int,int>mp;
        int i=0, j=0;

        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];

            if(j-i+1==k){
                if(mp.size()>=m){
                    ans=max(ans, sum);
                    sum-=nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                else{
                    mp[nums[i]]--;
                    sum-=nums[i];
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }

        return ans==INT_MIN? 0: ans;
    }
};