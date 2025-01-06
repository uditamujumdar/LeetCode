class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int>nums;
        for(int i=0;i<n;i++){
            nums.push_back(nums1[i]-nums2[i]);
        }
        long long ans=0;
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            int ub=upper_bound(temp.begin(), temp.end(), nums[i]+diff)-temp.begin();
            ans+=ub;
            int lb=lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
            temp.insert(temp.begin()+lb, nums[i]);
        }
        return ans;
    }
};

//nums1[i]-nums2[i]<=nums1[j]-nums2[j]+diff