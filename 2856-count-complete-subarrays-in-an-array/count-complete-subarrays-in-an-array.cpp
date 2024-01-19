class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        set<int>s;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                if(s.size()==st.size()){
                    ans++;
                }
            }
            s.clear();
        }

        return ans;
    }
};