class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& que) {
        int n=nums.size();
        map<int,int>mp;
        //starting to add 1 from index l onward).
        //the range ends at index r, and after r, we stop the effect of adding 1.
        for(int i=0;i<que.size();i++){
            mp[que[i][0]]++;
            mp[que[i][1]+1]--;
        }
        int ops=0;
        for(int i=0;i<n;i++){
            ops+=mp[i];
            if(ops<nums[i]){
                return false;
            }
        }
        return true;
    }
};