class Solution {
public:
    string smallestNumber(string pat) {
        string s="";
        stack<int>st;
        for(int i=0;i<=pat.size();i++){
            st.push(i+1);
            if(i==pat.size() || pat[i]=='I'){
                while(!st.empty()){
                    s.push_back(st.top()+'0');
                    st.pop();
                }
            }
        }
        return s;
    }
};