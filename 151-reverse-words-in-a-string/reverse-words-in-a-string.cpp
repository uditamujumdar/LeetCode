class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ') {
                if(!str.empty()) {
                    v.push_back(str);
                    str = "";
                }
            } 
            else{
                str+=s[i];
            }
        }
        if(!str.empty()){
            v.push_back(str);
        }

        reverse(v.begin(), v.end());
        string ans="";
        for(int i=0;i<v.size();i++){
            ans+=v[i];
            if(i!=v.size()-1)
            ans+=' ';
        }
        return ans;
    }
};