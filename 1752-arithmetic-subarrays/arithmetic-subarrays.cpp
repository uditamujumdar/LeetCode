class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++){
            vector<int>v;
            for(int j=l[i];j<=r[i];j++){
                v.push_back(nums[j]);
            }
            sort(v.begin(), v.end());
            int diff=v[1]-v[0];
            bool flag=true;
            for(int k=0;k<v.size()-1;k++){
                if(v[k+1]-v[k]!=diff){
                    ans.push_back(false);
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(true);
            }
        }

        return ans;
    }
};