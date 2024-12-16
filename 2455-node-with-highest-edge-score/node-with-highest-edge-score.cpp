class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        map<long long,long long>mp;
        for(int i=0;i<n;i++){
            mp[edges[i]]+=i;
        }
        long long maxi=-1;
        long long ind=0;
        for(auto it: mp){
            if(it.second==maxi){
                ind=min(ind,it.first);
            }
            if(it.second>maxi){
                maxi=it.second;
                ind=it.first;
            }
        }
        return ind;
    }
};