class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        sort(nums.begin(), nums.end());

        int i=n-1;
        for(int j=1;j<n;j+=2){
            v[j]=nums[i];
            i--;
        }
        for(int j=0;j<n;j+=2){
            v[j]=nums[i];
            i--;
        }
        nums=v;
    }
};