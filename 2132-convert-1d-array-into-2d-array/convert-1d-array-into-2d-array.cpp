class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        int o=original.size();
        if(o!=m*n){
            return ans;
        }
        for(int i=0;i<o;i++){
            if(v.size()<n){
                v.push_back(original[i]);
            }
            else{
                ans.push_back(v);
                v.clear();
                v.push_back(original[i]);
            }
        }
        ans.push_back(v);
        return ans;
    }
};