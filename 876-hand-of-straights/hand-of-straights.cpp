class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n=nums.size();
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