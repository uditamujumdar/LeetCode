class Solution {
public:
    int f(vector<int>& nums, int maxsum){
        int sum=0,x=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=maxsum){
                sum+=nums[i];
            }
            else{
                x++;
                sum=nums[i];
            }
        }
        return x;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=*max_element(nums.begin(), nums.end());
        int j=accumulate(nums.begin(), nums.end(),0);

        while(i<=j){
            int mid=i+(j-i)/2;
            int flag=f(nums, mid);

            if(flag>k){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return i;
    }
};