class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            vector<int>vv(3);
            vv[0]=intervals[i][0];
            vv[1]=intervals[i][1];
            vv[2]=i;
            v.push_back(vv);
        }
        sort(v.begin(), v.end());

        vector<int>ans(n, -1);
        for(int i=0;i<n;i++){
            int e=v[i][1];
            int ind=v[i][2];
            
            for(int j=i;j<n;j++){
                if(v[j][0]>=e){
                    ans[ind]=v[j][2];
                    break;
                }
            }
        }
        return ans;
    }
};