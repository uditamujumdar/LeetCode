class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int x='a'-'A';

        for(int i=s.size()-1;i>=0;i--){
            if(!st.empty() && abs(st.top()-s[i])==x){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};