class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mini=INT_MAX;
        int sum;

        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int x=nums[i]+nums[j]+nums[k];
                if(target>x){
                    j++;
                }
                else if(target<x){
                    k--;
                }
                else{
                    return x;
                }
                if(abs(x-target)<mini){
                    sum=x;
                    mini=abs(target-x);
                }
            }
        }
        return sum;
    }
};
