class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string>ans;
        int n=d[0].size();

        for(int i=0;i<q.size();i++){
            for(int j=0;j<d.size();j++){
                int cnt=0;
                for(int k=0;k<n;k++){
                    if(q[i][k]!=d[j][k]){
                        cnt++;
                    }
                }
                if(cnt<=2){
                    ans.push_back(q[i]);
                    break;
                }
            }
        }

        return ans;
    }
};