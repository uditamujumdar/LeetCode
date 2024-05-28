class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int cost=0;
        int i=0, j=0;
        int maxi=-1;

        while(j<n){
            cost+=abs(s[j]-t[j]);
            while(cost>maxCost){
                cost-=abs(s[i]-t[i]);
                i++;
            }
            maxi=max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};