class Solution {
public:
    int maxScore(string s) {
        int o=0;
        for(auto it: s){
            if(it=='1')o++;
        }
        if(o==0){
            return s.size()-1;
        }
        int maxi=-1;
        int sc=0, z=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                z++;
            }
            sc=z+(o-(i+1-z));
            maxi=max(maxi, sc);
        }
        return maxi;
    }
};