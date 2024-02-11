class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pat) {
        int m=pat.size();
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-m;i++){
            int ind=0;
            int flag=1;
            for(int j=i;j<=m+i-1;j++){
                if(pat[ind]==0){
                    if(nums[j]!=nums[j+1]){
                        flag=0;
                        break;
                    }
                }
                if(pat[ind]==-1){
                    if(nums[j+1]>=nums[j]){
                        flag=0;
                        break;
                    }
                }
                if(pat[ind]==1){
                    if(nums[j]>=nums[j+1]){
                        flag=0;
                        break;
                    }
                }
                ind++;
            }
            if(flag)cnt++;
        }
        return cnt;
    }
};