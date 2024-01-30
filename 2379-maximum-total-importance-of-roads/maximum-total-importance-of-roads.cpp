class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indeg(n, 0);
        for(auto it: roads){
            indeg[it[0]]++;
            indeg[it[1]]++;
        }

        long long ans=0;
        sort(indeg.begin(), indeg.end(), greater<int>());

        long long x=n;
        for(int i=0;i<indeg.size();i++){
            long long temp=(long long)indeg[i]*n;
            ans+=temp;
            n--;
        }
        return ans;
    }
};