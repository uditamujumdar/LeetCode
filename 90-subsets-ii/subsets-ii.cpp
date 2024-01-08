class Solution {
private:
    void solve(vector<int>& nums, vector<int> output, int i, set<vector<int>>& st){
        if(i<0){
            sort(output.begin(), output.end());
            st.insert(output);
            return;
        }

        //incl
        output.push_back(nums[i]);
        solve(nums, output, i-1, st);
        output.pop_back();
        
        //excl
        solve(nums, output, i-1, st);

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int>output;
        int ind=nums.size();
        solve(nums, output, ind-1, st);

        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};