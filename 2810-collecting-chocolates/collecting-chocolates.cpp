class Solution {
public:
    void rotate(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];
        for(int i=n-1;i>0;i--) 
            nums[i]=nums[i-1];
        nums[0] = last;
    }
    
    long long minCost(vector<int>& nums, int x) {
        long long cost=0;
        int n=nums.size();
        vector<long long>v(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            v[i]=nums[i];
            sum+=nums[i];
        }
        long long ans=sum;
        for(int i=1;i<n;i++){
            cost+=x;
            rotate(nums);
            long long x=0;
            for(int i=0;i<n;i++){
                v[i]=min(v[i], (long long)nums[i]);
                x+=v[i];
            }
            ans=min(ans, x+cost);
        }
        return ans;
    }
};