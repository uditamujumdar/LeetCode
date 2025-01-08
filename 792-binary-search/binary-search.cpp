class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0, j=n-1;

        while(i<=j){
            if(nums[i]>target){
                j--;
            }
            else if(nums[i]<target){
                i++;
            }
            else{
                return i;
            }
        }
        return -1;
    }
};
//I reach for you, but you're not there,
//all I feel is cold despair.