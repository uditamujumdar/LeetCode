class Solution {
public:
    int largestCombination(vector<int>& cand) {
        vector<int>bits(32,0);
        for(auto it: cand){
            int temp=31;
            while(it>0){
                bits[temp]+=it&1;
                it/=2;
                temp--;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            ans=max(ans, bits[i]);
        }
        return ans;
    }
};