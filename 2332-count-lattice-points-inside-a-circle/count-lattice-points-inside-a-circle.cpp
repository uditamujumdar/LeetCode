class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>st;
        for(int i=0;i<circles.size();i++){
            int x=circles[i][0];
            int y=circles[i][1];
            int z=circles[i][2];
            for(int j=-z;j<=z;j++){
                for(int k=-z;k<=z;k++){
                    if(j*j + k*k<=z*z){
                        st.insert({x+j,y+k});
                    }
                }
            }
        }
        return (int)st.size();
    }
};