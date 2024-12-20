class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0;
        int seg=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
            }
            else{
                if(cnt>=1){
                    seg++;
                }
                cnt=0;
            }
        }
        if(cnt>=1){
            seg++;
        }
        return seg<=1;
    }
};