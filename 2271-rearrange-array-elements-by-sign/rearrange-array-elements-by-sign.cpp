class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==2 && nums[0]<0)
        {
            swap(nums[0],nums[n-1]);
            return nums;
        }
        if(nums.size()==2 && nums[0]>0)
        {
            return nums;
        }

        vector<int>a, b, c;
        for(auto it: nums){
            if(it<0)a.push_back(it);
            else b.push_back(it);
        }

        for(int i=0;i<a.size();i++){
            c.push_back(b[i]);
            c.push_back(a[i]);
        }

        return c;

    }
};