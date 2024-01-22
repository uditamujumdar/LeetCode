class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        map<int, int>mp;
        for(int i=1;i<=n;i++){
            mp[i]=0;
        }

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        for (auto it : mp) {
        if (it.second == 0) {
            ans.push_back(it.first);
        }
    }


        return ans;
    }
};