class Solution {
public:
    long long max(long long a, long long b){
        if(a>b)return a;
        return b;
    }

    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long i=0;
        long long j=0;
        map<int,int>mp;
        long long ans=0;
        long long n=nums.size();
        long long sum=0;
        while(j<n)
        {
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1==k)
            {
               if(mp.size()==k)
               {
                    ans=max(ans,sum);
                    sum=sum-nums[i];
                    mp.erase(nums[i]);
                    i++;
               } 
               else
               {
                  sum=sum-nums[i];
                  mp[nums[i]]--;
                  if(mp[nums[i]]==0)
                  mp.erase(nums[i]);
                  
                  i++;
               }
            }
            j++;
        }
        return ans;
    }
};