class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int, int>>vis;
        int x=0, y=0;
        vis.push_back({x,y});
        for(int i=0;i<path.length();i++){
            if(path[i]=='N') y++;
            if(path[i]=='S') y--;
            if(path[i]=='E') x++;
            if(path[i]=='W') x--;

            vis.push_back({x,y});
        }

        set<pair<int, int>>st(vis.begin(), vis.end());
        if(vis.size()==st.size()){
            return false;
        }
        else{
            return true;
        }
    }
};