class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& que, int x) {
        int n=nums.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<int>ans;

        for(auto it: que){
            if(mp[x].size()<it){
                ans.push_back(-1);
            }
            else{
                ans.push_back(mp[x][it-1]);
            }
        }
        return ans;
    }
};