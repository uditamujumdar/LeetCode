class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;

        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                cnt++;
                nums[i]=1;
                nums[i+1]=abs(nums[i+1]-1);
                nums[i+2]=abs(nums[i+2]-1);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                return -1;
            }
        }
        return cnt;
    }
};