class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        map<int,vector<int>>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]].push_back(i);
        }
        int start=-1,end=-1;
        for(int i=0;i<v.size();i++){
            if(find(mp[nums[i]].begin(), mp[nums[i]].end(),i)==mp[nums[i]].end()){
                if(start==-1){
                    start=i;
                }
                end=i;
            }
        }
        if(start==-1){
            return 0;
        }
        return end-start+1;
    }
};