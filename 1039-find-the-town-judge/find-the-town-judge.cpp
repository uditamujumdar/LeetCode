class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans=-1;

        vector<int>a(n+1, 0);
        vector<int>b(n+1, 0);

        //a-->0
        //b-->n-1

        for(int i=0;i<trust.size();i++){
            a[trust[i][0]]++;
            b[trust[i][1]]++;
        }

        for(int i=1;i<=n;i++){
            if(a[i]==0 && b[i]==n-1){
                ans=i;
            }
        }

        return ans;
    }
};