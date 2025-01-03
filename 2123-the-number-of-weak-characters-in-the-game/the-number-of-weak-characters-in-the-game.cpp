class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n=prop.size();
        sort(prop.begin(), prop.end(),cmp);
        int ans=0;
        int maxi=-1;

        for(int i=n-1;i>=0;i--){
            if(maxi>prop[i][1]){
                ans++;
            }
            else{
                maxi=prop[i][1];
            }
        }
        return ans;
    }
};