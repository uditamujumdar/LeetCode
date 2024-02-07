class Solution {
public:
    int minSwaps(string s) {
        int cnt=0;
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                st.push('[');
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    cnt++;
                }
            }
        }
        return (cnt+1)/2;
    }
};