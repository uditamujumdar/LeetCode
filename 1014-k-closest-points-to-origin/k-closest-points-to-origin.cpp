class Solution {
public:
    static int comp(vector<int>& a, vector<int>& b){
        int x=a[0]*a[0]+a[1]*a[1];
        int y=b[0]*b[0]+b[1]*b[1];

        return x<y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);

        vector<vector<int>>ans;
        
        for(int i=0;i<k;i++){
            vector<int>x;
            x.push_back(points[i][0]);
            x.push_back(points[i][1]);
            ans.push_back(x);
        }

        return ans;
    }
};