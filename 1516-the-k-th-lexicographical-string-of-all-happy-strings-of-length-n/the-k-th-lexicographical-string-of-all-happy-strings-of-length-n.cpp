class Solution {
public:
    void f(int n, int k, string& s, vector<char>& v, vector<string>& ans){
        if(ans.size()==k){
            return;
        }

        if(s.size()==n){
            ans.push_back(s);
            return;
        }

        for(int i=0;i<3;i++){
            if(s.size()==0 || s.back()!=v[i]){
                s.push_back(v[i]);
                f(n,k,s,v,ans);
                s.pop_back();                
            }
        }
        return;
    }

    string getHappyString(int n, int k) {
        string s="";
        vector<char>v={'a', 'b', 'c'};
        vector<string>ans;

        f(n,k,s,v,ans);

        if(ans.size()==k){
            return ans.back();
        }
        return "";
    }
};