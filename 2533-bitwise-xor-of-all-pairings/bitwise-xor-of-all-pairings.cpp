class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        
        if(m%2==1){
            for(auto it: nums1){
                ans^=it;
            }
        }
        if(n%2==1){
            for(auto it: nums2){
                ans^=it;
            }
        }
        return ans;
    }
};