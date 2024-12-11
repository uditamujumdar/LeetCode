class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        sort(nums.begin(), nums.end());
        for(auto it: nums){
            mp[it]++;
        }
        int maxi=-1, cnt=0;
        int i=nums[0], j=nums[0];
        while(j<=nums[n-1]){
            cnt+=mp[j];
            while(j-i>2*k){
                cnt-=mp[i];
                i++;
            }
            maxi=max(maxi, cnt);
            j++;
        }
        return maxi;
    }   
};
//-1 0 2 4
//3 4 6 8