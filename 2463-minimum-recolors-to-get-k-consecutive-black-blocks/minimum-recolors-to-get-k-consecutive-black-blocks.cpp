class Solution {
public:
    int minimumRecolors(string bl, int k) {
        int cnt=0, ops=0;
        int n=bl.length();
        int mini=INT_MAX;
        int i=0, j=0;
        while(j<n){
            if(bl[j]=='B'){
                cnt++;
            }
            else{
                ops++;
                cnt++;
            }
            while(cnt>=k){
                mini=min(mini, ops);
                cnt--;
                if(bl[i]=='W')ops--;
                i++;
            }
            j++;
        }
        return mini;
    }
};