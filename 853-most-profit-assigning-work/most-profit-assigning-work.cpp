class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        int n=diff.size();
        int m=worker.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({diff[i], profit[i]});
        }
        sort(vp.begin(), vp.end());
        int ans=0;

        for(int i=0;i<m;i++){
            int low=0, high=n-1;
            int res=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(vp[mid].first<=worker[i]){
                    res=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            if(res!=-1){
                int maxi=0;
                for(int i=0;i<=res;i++){
                    maxi=max(maxi, vp[i].second);
                }
                ans+=maxi;
            }
        }
        return ans;
    }
};