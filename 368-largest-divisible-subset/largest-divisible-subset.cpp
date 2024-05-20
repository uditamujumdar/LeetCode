class Solution {
public:
    vector<int> ans;
    void lds(vector<int> temp,int i,int prev,vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()){
            if(temp.size()>ans.size()) ans=temp;
            return;
        }
        
        if((int)temp.size()>dp[i] && (nums[i]%prev==0)){ 
            dp[i]=temp.size();
            temp.push_back(nums[i]);
            lds(temp,i+1,nums[i],nums, dp);
            temp.pop_back();
        }
        lds(temp,i+1,prev,nums, dp);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n, -1);
        vector<int> temp;
        lds(temp,0,1,nums,dp);
        return ans;
    }
};