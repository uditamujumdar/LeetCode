class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        vector<int>len(n,0);
        len[0]=1;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                len[i]=len[i-1]+1;
            }
            else{
                len[i]=1;
            }
        }
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(len[i]);
        }
        map<char,vector<int>>top;

        for(auto it: mp){
            vector<int>v=it.second;
            sort(v.rbegin(),v.rend());

            int mini=min(3, (int)v.size());
            for (int i=0;i<mini;i++) {
                top[it.first].push_back(v[i]);  
            }
        }

        int ans=-1;
        for(auto it: top){
            vector<int>v=it.second;
            if(v.size()>=3){
                ans=max(ans, v[2]);
            }
        }
        return ans;
    }
};