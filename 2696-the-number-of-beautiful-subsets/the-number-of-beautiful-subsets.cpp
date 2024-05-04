class Solution {
public:
    void f(vector<int>& nums, int k, int& ans, int ind, vector<int>&v){
        int n=nums.size();
        if(ind==n){
            if(v.size()>0){
                ans++;
            }
            return;
        }

        if(find(v.begin(), v.end(), nums[ind]-k)==v.end()){

            v.push_back(nums[ind]);
            f(nums,k,ans,ind+1,v);
            v.pop_back();
        }

        f(nums,k,ans,ind+1,v);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=0;
        vector<int>v;
        f(nums, k, ans, 0, v);
        return ans;
    }
};


        