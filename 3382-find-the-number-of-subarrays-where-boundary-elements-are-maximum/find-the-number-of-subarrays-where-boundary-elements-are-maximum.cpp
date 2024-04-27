class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;

        //next greater element
        vector<int>v(n,0);
        v[n-1]=n-1;
        int z=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[v[z]]){
                z=i;
            }
            v[i]=z;
        }

        vector<int>vec(n,0);
        for(int i=0;i<n;i++){
            if(vec[i]){
                //already included
                continue;
            }
            long long cnt=1;
            for(int j=i+1;j<v[i]+1;j++){
                if(nums[j]>nums[i])break;
                if(nums[i]==nums[j]){
                    cnt++;
                    vec[j]++;
                }
            }
            ans+=(cnt*(cnt+1)/2);
        }

        return ans;
    }
};