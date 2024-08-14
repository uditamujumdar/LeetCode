class Solution {
public:
    int f(vector<int>& nums, int k){
        int n=nums.size();
        int cnt=0;
        int left=0;
        for(int right=1;right<n;right++){
            while(nums[right]-nums[left]>k){
                left++;
            }
            cnt+=right-left;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=nums.back()-nums.front();

        while(i<j){
            int mid=i+(j-i)/2;
            if(f(nums,mid)<k){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return i;
    }
};