#define ll long long 
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(), beans.end());
        ll total=accumulate(beans.begin(), beans.end(),0ll);
        ll ans=total-((ll)n*beans[0]);

        for(int i=1;i<n;i++){
            ans=min(ans, total-(ll)(n-i)*beans[i]);
        }

        return ans;
    }
};