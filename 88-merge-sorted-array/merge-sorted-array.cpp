class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        vector<int>temp;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                temp.push_back(nums1[i++]);
            }
            else{
                temp.push_back(nums2[j++]);
            }
        }
        while(i<m){
            temp.push_back(nums1[i++]);
        }
        while(j<n){
            temp.push_back(nums2[j++]);
        }

        nums1.clear();
        nums1=temp;
    }
};

//dear diary, just typing shedding tears for no reason :(