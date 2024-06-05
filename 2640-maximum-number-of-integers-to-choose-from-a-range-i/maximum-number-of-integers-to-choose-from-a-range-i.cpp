class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(auto it: banned){
            st.insert(it);
        }
        int sum=0, ans=0;

        for(int i=1;i<=n;i++){
            if(st.count(i)==0 && maxSum>=sum+i){
                sum+=i;
                ans++;
            }
        }   
        return ans;
    }
};