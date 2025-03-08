class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[nums[i]&nums[j]]++;
            }
        }
        
        int cnt=0;
        for(auto it: nums){
            for(auto iter: mp){
                if((it&iter.first)==0){
                    cnt+=iter.second;
                }
            }
        }

        return cnt;
    }
};