class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //XOR operator cancels equal terms

        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans^=nums[i];
        }

        return ans;
    }
};