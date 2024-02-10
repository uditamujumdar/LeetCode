class Solution {
public:
    string finalString(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='i'){
                reverse(s.begin(), s.begin()+i);
            }
        }
        string ans="";
        for(auto it: s){
            if(it=='i'){
                continue;
            }
            else{
                ans+=it;
            }
        }
        return ans;
    }
};