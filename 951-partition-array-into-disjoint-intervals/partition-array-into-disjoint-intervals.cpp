class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int>suff(n);

        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=min(suff[i+1], nums[i]);
        }

        int maxi=0;

        for(int i=0;i<n;i++){
            maxi=max(maxi, nums[i]);
            if(maxi<=suff[i+1]){
                return i+1;
            }
        }
        return 0;
    }
};
//0,0,3,6,6