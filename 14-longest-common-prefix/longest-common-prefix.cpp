class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string s=strs[0];
        string t=strs[n-1];

        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==t[i]){
                ans+=s[i];
            }
            else break;
        }
        return ans;
    }
};