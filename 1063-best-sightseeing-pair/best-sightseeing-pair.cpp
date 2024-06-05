class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int val=values[0],ans=0;

        for(int i=1;i<n;i++){
            ans=max(ans, val+values[i]-i);
            // cout<<ans<<endl;
            val=max(val, values[i]+i);
        }
        return ans;
    }
};