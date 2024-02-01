class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int>v;
        vector<vector<int>>ans;
      
        for(int i=0;i<nums.size();i++){
            if(v.size()==3){
                    int d1=abs(v[1]-v[0]);
                    int d2=abs(v[2]-v[1]);
                    int d=abs(v[2]-v[0]);
                    if(d>k || d1>k || d2>k){
                        ans.erase(ans.begin(), ans.end());
                        return ans;
                    }
                
                ans.push_back(v);
                v.erase(v.begin(), v.end());
            }
            v.push_back(nums[i]);
        }
        int d1=abs(v[1]-v[0]);
                    int d2=abs(v[2]-v[1]);
                    int d=abs(v[2]-v[0]);
                    if(d>k || d1>k || d2>k){
                        ans.erase(ans.begin(), ans.end());
                        return ans;
                    }
        ans.push_back(v);
        
        
        return ans;
    }
};