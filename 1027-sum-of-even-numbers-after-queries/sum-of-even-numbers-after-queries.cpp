class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int q=queries.size();
        int n=nums.size();

        int tot=0;
        for(auto it: nums){
            if(it%2==0) tot+=it;
        }

        for(int i=0;i<q;i++){
            int val=queries[i][0];
            int ind=queries[i][1];

            if(nums[ind]&1){
                nums[ind]+=val;
                if(abs(nums[ind])%2==0){
                    tot+=nums[ind];
                }
            }
            else{
                tot-=nums[ind];
                nums[ind]+=val;
                if(abs(nums[ind])%2==0){
                    tot+=nums[ind];
                }
            }
            ans.push_back(tot);
        }

        return ans;
    }
};