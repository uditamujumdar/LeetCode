class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans=0;
        int score=INT_MAX;

        for(auto it: nums){
            score&=it;
        }

        if(score!=0){
            return 1;
        }
        score=INT_MAX;

        for(int i=0;i<nums.size();i++){
            score&=nums[i];
            if(score==0){
                ans++;
                score=INT_MAX;
            }
        }

        return ans;
    }
};