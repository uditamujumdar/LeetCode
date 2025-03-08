class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n=nums.size();
        int xorr=nums[0];
        for(int i=1;i<n;i++){
            xorr^=nums[i];
        }
        if(xorr==0){
            return true;
        }
        return n%2==0;
    }
};