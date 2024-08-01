class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int ans=0;
        int o=0, c=0;
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                if(o==0){
                    ans++;
                    o++;
                }
                else{
                    o--;
                }
            }
            else{
                o++;
            }
        }
        return ans;
    }
};