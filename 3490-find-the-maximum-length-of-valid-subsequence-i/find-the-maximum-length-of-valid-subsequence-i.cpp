class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int o=0,e=0;
        for(auto it: nums){
            if(it&1)o++;
            else e++;
        }

        int j=0;
        for(int i=0;i<n;i++){
            if(j%2==nums[i]%2){
                j++;
            }
        }
        int k=0;
        for(int i=0;i<n;i++){
            if(k%2!=nums[i]%2){
                k++;
            }
        }

        return max(max(e,o),max(j,k));
    }
};