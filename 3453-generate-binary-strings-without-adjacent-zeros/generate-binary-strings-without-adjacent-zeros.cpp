class Solution {
public:
    void f(int n, vector<string>&ans, string s){
        if(s.length()==n){
            ans.push_back(s);
            return;
        }
        if(s.length()==0){
            s.push_back('0');
            f(n,ans,s);
            s.pop_back();
            s.push_back('1');
            f(n,ans,s);
            s.pop_back();
        }
        else{
            if(s.back()=='1'){
                s.push_back('0');
                f(n,ans,s);
                s.pop_back();
                s.push_back('1');
                f(n,ans,s);
                s.pop_back();
            }
            else{
                s.push_back('1');
                f(n,ans,s);
                s.pop_back();
            }
        }
        return;
    }
    
    vector<string> validStrings(int n) {
        if(n==1){
            return {"0", "1"};
        }
        vector<string>ans;
        string s="";
        
        f(n,ans,s);
        return ans;
    }
};