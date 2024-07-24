class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        vector<int>v(1e5, 0);

        for(int i=0;i<trips.size();i++){
            v[trips[i][1]]+=trips[i][0];
            v[trips[i][2]]-=trips[i][0];
        }
        int curr=0;
        for(int i=0;i<v.size();i++){
            curr+=v[i];
            if(curr>cap){
                return false;
            }
        }
        return true;
    }
};