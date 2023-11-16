class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        vector<int>ans(2, -1);
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(abs(i-j)>=indexDiff && abs(nums[i]-nums[j])>=valueDiff){
                    ans[0]=i;
                    ans[1]=j;
                }
            }
        }
        return ans;
    }
};