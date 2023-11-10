class Solution {
public:
    void bubble(vector<int>& nums, int n){
        int i, j;
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    void sortColors(vector<int>& nums) {
        int n=nums.size();
        return bubble(nums, n);
    }
};