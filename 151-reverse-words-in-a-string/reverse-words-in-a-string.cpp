class Solution {
public:
    string reverseWords(string str) {
        int n=str.length();

        vector<string>v;
        string s="";

        for(int i=0;i<n;i++){
            if(str[i]==' '){
                if(s.size()>0 && s[0]!=' ')
                v.push_back(s);
                s="";
            }
            else{
                s+=str[i];
            }
        }
        if(!s.empty()){
            v.push_back(s);
        }

        string ans="";
        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i];
            ans+=' ';
        }
        ans.pop_back();

        return ans;
    }
};