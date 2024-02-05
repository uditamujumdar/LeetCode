class Solution {
public:
    int f(vector<int>& nums, int goal){
        if(goal<0)
            return 0;

        int sum=0;
        int i=0;
        int j=0;
        int res=0;

        while(j<nums.size()){
            //we're iterating over the nums array and 
            //then adding the current element into the sum
            sum+=nums[j]; 
            
            //if our current sum is greater than our goal
            //that means we don't need the extra element
            //so we will shrink our window by subtracting 
            //the ith elements from sum till sum > goal
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            //We're adding the length of each subarray 
            //to our result
            res+=(j-i+1);
            
            j++;
        }
        
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal)-f(nums,goal-1);
    }
};