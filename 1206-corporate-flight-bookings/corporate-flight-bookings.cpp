class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& book, int n) {
        vector<int>pref(n+1,0);

        for(int i=0;i<book.size();i++){
            int f=book[i][0];
            int l=book[i][1];
            for(int j=f;j<=l;j++){
                pref[j]+=book[i][2];
            }
        }

        vector<int>ans;
        for(int i=1;i<n+1;i++){
            ans.push_back(pref[i]);
        }
        return ans;
    }
};