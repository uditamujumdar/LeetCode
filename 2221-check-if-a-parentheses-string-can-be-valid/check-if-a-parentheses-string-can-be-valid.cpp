class Solution {
public:
    bool canBeValid(string s, string l) {
        stack<pair<char,int>>st;
        int n=s.length();
        if(n&1){
            return false;
        }
        
        int o=0, c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || l[i]=='0'){
                o++;
            }
            else{
                o--;
            }
            if(o<0){
                return false;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || l[i]=='0'){
                c++;
            }
            else{
                c--;
            }
            if(c<0){
                return false;
            }
        }
        return true;
    }
};