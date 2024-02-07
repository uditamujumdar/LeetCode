class Solution {
public:
    string removeStars(string s) {
        string ans="";
        stack<char>st;

        for(int i=0;i<s.length();i++){
            st.push(s[i]);
            if(st.top()=='*'){
                st.pop();
                st.pop();
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};