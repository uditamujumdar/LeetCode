class Solution {
public:
    vector<int> f(string s){
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='+'||ch=='-'||ch=='*'){
                vector<int>left=f(s.substr(0,i));
                vector<int>right=f(s.substr(i+1));

                for(auto it: left){
                    for(auto it2: right){
                        if(ch=='+'){
                            ans.push_back(it+it2);
                        }
                        if(ch=='-'){
                            ans.push_back(it-it2);
                        }
                        if(ch=='*'){
                            ans.push_back(it*it2);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(s));
        }
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return f(expression);
    }
};