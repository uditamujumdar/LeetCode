class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bool flag=false;
        set<int>st;
        for(auto it: nums){
            st.insert(it);
            if(it<k){
                return -1;
            }
            if(it==k){
                flag=true;
            }
        }
        if(flag){
            return st.size()-1;
        }
        return st.size();
    }
};