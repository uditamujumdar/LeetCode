class Solution {
public:
    bool check(int a, int b, int c){
        if((a*a)+(b*b)<=(c*c)){
            return true;
        }
        return false;
    }

    vector<int> countPoints(vector<vector<int>>& pts, vector<vector<int>>& que) {
        vector<int>ans;
        int n=que.size();
        int p=pts.size();

        for(int i=0;i<n;i++){
            int x1=que[i][0];
            int y1=que[i][1];
            int r=que[i][2];
            int cnt=0;
            for(int j=0;j<p;j++){
                int x=pts[j][0];
                int y=pts[j][1];

                if(check(x-x1, y-y1, r))cnt++;
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};