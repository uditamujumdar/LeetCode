class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int ans=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                ans++;
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                    ans--;
                }
                else{
                    ans++;
                }
            }
        }

        return ans;
    }
};