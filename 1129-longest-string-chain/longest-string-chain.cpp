class Solution {
public:
    static bool cmp(string& a, string& b){
        return a.size() < b.size();
    }

    bool check(string& s, string& t){
        if(s.size() != t.size()+1){
            return false;
        }
        int i=0, j=0;
        while(i<s.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s.size() && j==t.size()){
            return true;
        }
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int>dp(n, 1);
        int maxi=1;

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i], words[prev]) && dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }

        return maxi;
    }
};