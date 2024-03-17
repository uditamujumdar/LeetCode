class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        string ans="";
        unordered_map<string, string>mp;

        for(int i=0;i<know.size();i++){
            mp[know[i][0]]=know[i][1];
        }
        string x="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                i++;
                while(s[i]!=')'){
                    x+=s[i];
                    i++;
                }
                if(mp.find(x)!=mp.end()){
                    ans+=mp[x];
                }
                else{
                    ans+='?';
                }
                x="";
            }
            else{
                ans+=s[i];
            }
        }

        return ans;
    }
};