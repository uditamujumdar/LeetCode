class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int maxi=INT_MIN;

        int s=0, e=n-1;
        while(s<e){
            maxi=max(maxi, nums[s]+nums[e]);

            s++;
            e--;
        }

        return maxi;
    }
};