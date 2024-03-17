class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        if(n==0){
            return true;
        }
        int push_ind=1;
        int pop_ind=0;

        stack<int>st;
        st.push(pushed[0]);

        while(push_ind<n && pop_ind<n){
            if(!st.empty() && st.top()==popped[pop_ind]){
                st.pop();
                pop_ind++;
            }
            else{
                st.push(pushed[push_ind]);
                push_ind++;
            }
        }

        while(pop_ind<n){
            if(!st.empty() && st.top()==popped[pop_ind]){
                st.pop();
                pop_ind++;
            }
            else{
                return false;
            }
        }

        return true;
    }
};