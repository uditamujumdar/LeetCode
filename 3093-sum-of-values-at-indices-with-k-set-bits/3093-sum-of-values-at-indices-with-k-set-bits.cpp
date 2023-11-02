class Solution {
public:
    int countset(int n){
        int c=0;
        while(n!=0){
            c+=n&1;
            n=n>>1;
        }

        return c;
    }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(countset(i)==k)
            ans+=nums[i];
        }

        return ans;
    }
};