class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int n=p.size();
        sort(p.begin(), p.end());
        
        int i=0,j=n-1;
        int ans=0;
        
        while(i<=j){
            if(p[i]+p[j]<=limit){
                i++;
                j--;
                ans++;
            }
            else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};