class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        // int num=*min_element(nums.begin(), nums.end());
        if(n%k!=0){
            return false;
        }

        map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }

        for(auto it: mp){
            if(it.second>0){
                for(int i=0;i<k;i++){
                    if(mp[it.first+i]<it.second){
                        return false;
                    }
                    else{
                        mp[it.first+i]-=it.second;
                    }
                }
            }
        }

        return true;
    }
};