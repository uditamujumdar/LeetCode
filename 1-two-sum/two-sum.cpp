class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n=nums.size();
        int ans1=-1, ans2=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && nums[i]+nums[j]==tar){
                    ans1=i;
                    ans2=j;
                    break;
                }
            }
        }
        return {ans1, ans2};
    }
};