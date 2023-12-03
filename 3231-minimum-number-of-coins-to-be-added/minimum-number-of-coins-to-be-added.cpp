class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n=coins.size();
        sort(coins.begin(), coins.end());
        int ans=0;
        int presum=0;
        int ind=0;

        while(presum<target){
            if(ind<n && coins[ind]<=presum+1){
                presum+=coins[ind];
                ind++;
            }
            else{
                presum+=presum+1;
                ans++;
            }
        }

        return ans;
    }
};