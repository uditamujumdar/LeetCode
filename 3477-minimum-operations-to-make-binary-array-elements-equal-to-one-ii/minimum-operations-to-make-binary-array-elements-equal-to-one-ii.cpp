class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool flip=0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1 && flip){
                ans++;
                flip=0;
            }   
            else if(nums[i]==0 && !flip){
                ans++;
                flip=1;
            }
        }
        return ans;
    }
};