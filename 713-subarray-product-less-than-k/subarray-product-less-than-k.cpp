class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0;
        int i=0,j=0;
        int pr=1;
        if(k==0||k==1){
            return 0;
        }
        
        while(j<nums.size()){
            pr*=nums[j];
            while(pr>=k && i<nums.size()){
                pr/=nums[i];
                i++;
            }
            if(pr<k){
                cnt+=j-i+1;
            }
            j++;
        }
        return cnt;
    }
};