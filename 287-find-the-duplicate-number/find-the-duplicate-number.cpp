class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(auto it: nums){
            int ind=abs(it);
            //if already negative-->the no has been visited already
            if(nums[ind]<0){
                return ind;
            }
            nums[ind]=-nums[ind];
        }

        //TC=O(n) SC=O(1)
        return n;
    }
};