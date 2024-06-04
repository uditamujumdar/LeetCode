class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int maxi=stones[1]-0;

        for(int i=1;i<n-1;i++){
            maxi=max(maxi, stones[i+1]-stones[i-1]);
        }
        return maxi;
    }
};