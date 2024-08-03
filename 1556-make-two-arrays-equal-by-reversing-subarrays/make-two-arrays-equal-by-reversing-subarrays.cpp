class Solution {
public:
    bool canBeEqual(vector<int>& tar, vector<int>& arr) {
        map<int,int>mp,mpt;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: tar){
            mpt[it]++;
        }
        for(auto it: tar){
            if(mp.find(it)==mp.end() || mp[it]<mpt[it]){
                return false;
            }
        }
        return true;
    }
};