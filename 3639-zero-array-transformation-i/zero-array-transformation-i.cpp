class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& que) {
        int n=nums.size();
        vector<int>diff(n, 0);

        for(auto it: que){
            int l=it[0];
            int r=it[1];
            diff[l]++;
            if(r<n-1){
                diff[r+1]--;
            }
            //to end the decrements at index r only
        }

        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            cnt+=diff[i];
            if(cnt<nums[i]){
                return false;
            }
        }
        return true;
    }
};