class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nu, int diff, vector<vector<int>>& que) {
        vector<pair<int,int>>nums(n);
        for(int i=0;i<n;i++){
            nums[i]={nu[i], i};
        }
        sort(nums.begin(), nums.end());

        vector<int>geti(n);
        for(int i=0;i<n;i++){
            geti[nums[i].second]=i;
        }

        int st[100005][18];
        int l=0;
        for(int r=0;r<n;r++){
            while(nums[r].first-nums[l].first>diff){
                st[l][0]=r-1;
                l++;
            }
        }

        while(l<n){
            st[l][0]=n-1;
            l++;
        }

        for(int j=1;j<18;j++){
            for(int i=0;i<n;i++){
                st[i][j]=st[st[i][j-1]][j-1];
            }
        }

        vector<int>ans(que.size(), -1);
        for(int i=0;i<que.size();i++){
            int a=geti[que[i][0]];
            int b=geti[que[i][1]];
            if(a>b)swap(a,b);

            if(a==b){
                ans[i]=0;
                continue;
            }

            int curr=a;
            int steps=0;
            for(int j=17;j>=0;j--){
                if(st[curr][j]<b){
                    curr=st[curr][j];
                    steps+=(1<<j);
                }
            }

            if(st[curr][0]>=b){
                ans[i]=steps+1;
            }
            else{
                ans[i]=-1;
            }
        }

        return ans;
    }
};