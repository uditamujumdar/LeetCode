class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int z=0, o=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                o++;
            }
            else{
                z++;
                z=min(z,o);
            }
        }
        return z;
    }
};