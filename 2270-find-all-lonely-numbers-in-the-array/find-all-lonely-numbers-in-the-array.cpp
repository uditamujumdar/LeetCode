class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int>ans;

        if(n==1){
            ans.push_back(nums[0]);
            return ans;
        }
        
        if(nums[0]!=nums[1] && nums[0]!=nums[1]-1){
            ans.push_back(nums[0]);
        }
        if(nums[n-1]!=nums[n-2] && nums[n-1]!=nums[n-2]+1){
            ans.push_back(nums[n-1]);
        }

        for(int i=1;i<n-1;i++){
            if(nums[i-1]!=nums[i]-1 && nums[i]+1!=nums[i+1] && nums[i]!=nums[i+1] &&
                 nums[i]!=nums[i-1]){
                    ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};