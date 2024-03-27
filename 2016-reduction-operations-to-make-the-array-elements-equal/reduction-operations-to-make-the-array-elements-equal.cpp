class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        set<int>st;
        int mini=nums[0];
        for(auto it: nums){
            if(it!=mini){
                st.insert(it);
            }
        }
        int ind=1;
        int ans=0;
        for(auto it: st){
            ans+=(ind*mp[it]);
            ind++;
        }

        return ans;
    }
};