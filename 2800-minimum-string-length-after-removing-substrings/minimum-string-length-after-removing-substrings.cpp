class Solution {
public:
    int minLength(string s) {
        int n=s.length();

        stack<char>st;
        for(auto it: s){
            if(!st.empty()){
                if((it=='B'&&st.top()=='A')||(it=='D'&&st.top()=='C')){
                    st.pop();
                }
                else{
                    st.push(it);
                }
            }
            else{
                st.push(it);
            }
        }

        return st.size();
    }
};