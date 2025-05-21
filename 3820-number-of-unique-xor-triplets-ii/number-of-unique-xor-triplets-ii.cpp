class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st, ans;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }

        for(auto it: st){
            for(auto iter: nums){
                ans.insert(it^iter);
            }
        }

        return ans.size();
    }
};