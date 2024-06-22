class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0;
        int ans=0,cnt=0,odd=0;

        while(j<n){
            if(nums[j]&1){
                odd++;
                cnt=0;
            }
            while(odd==k){
                cnt++;
                odd-=nums[i++]&1;
            }
            ans+=cnt;
            j++;
        }
        return ans;
    }
};