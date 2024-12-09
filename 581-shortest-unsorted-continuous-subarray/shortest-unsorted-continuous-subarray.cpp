class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int st=-1, end=-1;
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<maxi){
                end=i;
            }
            else{
                maxi=nums[i];
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>mini){
                st=i;
            }
            else{
                mini=nums[i];
            }
        }
        if(st==-1 || end==-1)return 0;
        
        return end-st+1;
    }
};