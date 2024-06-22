class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=min(nums[i]%3, 3-nums[i]%3);
        }
        return cnt;
    }
};