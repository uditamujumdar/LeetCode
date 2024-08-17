class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            return {nums[0]};
        }
        if(k==1){
            return nums;
        }
        vector<int>ans;
        int i=0, j=1;
        int flag=-1;

        while(j<n){
            if(nums[j]-nums[j-1]!=1){
                flag=j;
            }
            if(j-i+1==k){
                if(flag>i){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(nums[j]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};