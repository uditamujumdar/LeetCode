class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]%2==0 && nums[i]<=threshold){
                int cnt=1;
                for(int j=i;j<n-1;j++){
                    if(nums[j]%2 != nums[j+1]%2 && nums[j+1]<=threshold){
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
                maxi=max(maxi, cnt);
            }
        }

        if(maxi==INT_MIN){
            return 0;
        }
        return maxi;
    }
};