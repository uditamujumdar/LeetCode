class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.length();
        int i=0, j=1;
        if(n==1){
            return 1;
        }
        int maxi=1;

        while(j<n){
            if(s[j]-s[i]==j-i){
                j++;
                maxi=max(maxi, j-i);
            }
            else{
                i=j;
                j++;
            }
        }
        return maxi;
    }
};