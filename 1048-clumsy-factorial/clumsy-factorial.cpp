class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        int i = 0;
        st.push(n);
        n--;

        while (n > 0) {
            if (i == 0) {
                int x = st.top();
                st.pop();
                st.push(x * n);
            } else if (i == 1) {
                int x = st.top();
                st.pop();
                st.push(x / n);
            } else if (i == 2) {
                int x = st.top();
                st.pop();
                st.push(x + n);
            } else if (i == 3) {
                st.push(-n);
            }
            i = (i + 1) % 4;
            n--;
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();st.pop();
        }
        return sum;
    }
};