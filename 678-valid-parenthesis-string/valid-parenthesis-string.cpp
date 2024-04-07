class Solution {
public:
    bool checkValidString(string s) {
        stack<char>st;
        stack<char>star;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }

        //if position of '*' is greater than '(' then it means we can convert some '*' to ')'
        while(!st.empty() && !star.empty() && star.top()>st.top()){
            st.pop();
            star.pop();
        }

        return st.empty();
    }
};