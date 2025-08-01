class Solution {
public:
    int f(vector<int>& nums, int goal){
        int n=nums.size();
        int ans=0;
        int i=0, j=0;
        int sum=0;
        if(goal<0){
            return 0;
        }

        while(j<n){
            sum+=nums[j];

            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal)-f(nums, goal-1);
    }
};