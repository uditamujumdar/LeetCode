class Solution {
public:
    bool isop(string& s){
        if(s.size()!=1){
            return false;
        }
        if(s[0]=='+'||s[0]=='-'||s[0]=='/'||s[0]=='*'){
            return true;
        }
        return false;
    }
    int solve(int op1, int op2, char op){
        if(op=='+'){
            return op1+op2;
        }
        if(op=='/'){
            return op1/op2;
        }
        if(op=='-'){
            return op1-op2;
        }
        if(op=='*'){
            return op1*op2;
        }
        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            if(isop(tokens[i])){
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                st.push(solve(op1, op2, tokens[i][0]));
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};