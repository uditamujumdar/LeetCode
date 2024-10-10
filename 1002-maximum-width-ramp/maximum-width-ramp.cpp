class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        v[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            v[i]=max(v[i+1],nums[i]);
        }

        int i=0, j=0;
        int maxi=0;

        while(j<n){
            while(i<j && nums[i]>v[j]){
                i++;
            }
            maxi=max(maxi, j-i);
            j++;
        }

        return maxi;
    }
};