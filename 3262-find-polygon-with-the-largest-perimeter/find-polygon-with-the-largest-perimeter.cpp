class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long maxi=-1;
        long long sum=nums[0]+nums[1];
        for(int i=2;i<nums.size();i++)
        {
            if(sum>nums[i])
            {
                sum+=nums[i];
                maxi=max(sum,maxi);
            }
            else
            {
                sum+=nums[i];
            }
        }
        return maxi;
    }
};