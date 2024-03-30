class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            return 1;
        }
        int mini=n+1;
        vector<int>bits(32);
        int i=0;
        for(int j=0;j<n;j++){
            int temp=0;
            for(int k=0;k<32;k++){
                if(nums[j]&(1<<k)){
                    bits[k]++;
                }
                if(bits[k]){
                    temp|=(1<<k);
                }
            }
            if(temp>=k){
                mini=min(mini, j-i+1);
            }
            while(temp>=k){
                temp=0;
                for(int k=0;k<32;k++){
                    if(nums[i]&(1<<k)){
                        bits[k]--;
                    }
                    if(bits[k]){
                        temp|=(1<<k);
                    }
                }
                i++;
                if(temp>=k){
                    mini=min(mini, j-i+1);
                }
            }
        }
        if(mini==n+1)return -1;

        return mini;
    }
};