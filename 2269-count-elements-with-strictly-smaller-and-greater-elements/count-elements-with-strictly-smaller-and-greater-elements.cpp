class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto it: nums){
            maxi=max(maxi, it);
            mini=min(mini, it);
        }

        int cnt=0;
        for(auto i: nums){
            if(i<maxi && i>mini)
            cnt++;
        }
        return cnt;
    }
};