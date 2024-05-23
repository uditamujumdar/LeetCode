class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int mini=INT_MAX, maxi=-1;
                for(auto it: mp){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};
