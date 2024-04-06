class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        vector<char>v(s.begin(), s.end());

        //mark excess closing parantheses
        for(int i=0;i<v.size();i++){
            if(v[i]=='('){
                open++;
            }
            else if(v[i]==')'){
                if(open==0){
                    v[i]='*';
                }
                else{
                    open--;
                }
            }
        }

        //mark excess opening parantheses
        for(int i=v.size()-1;i>=0;i--){
            if(open>0 && v[i]=='('){
                v[i]='*';
                open--;
            }
        }

        string ans="";
        for(auto it: v){
            if(it!='*'){
                ans+=it;
            }
        }

        return ans;
    }
};