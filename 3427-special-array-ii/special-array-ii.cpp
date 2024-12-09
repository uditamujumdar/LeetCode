class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        
        vector<bool>ans(n, false);
        vector<int>temp(nums.size(), 0);
        
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i]%2 == nums[i-1]%2) {
                temp[i] = temp[i-1]; 
                temp[i]++;
            }
            else temp[i]=temp[i-1];
        }
        
        for(int i = 0; i<n; i++) {
            if(temp[queries[i][0]] == temp[queries[i][1]]) ans[i] = true;
            
        }
        return ans;
    }
};

//0 0 1 1 