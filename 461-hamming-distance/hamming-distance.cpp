class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while(x!=0 || y!=0){
            int bitx=x&1;
            int bity=y&1;

            if(bitx!=bity){
                ans++;
            }
            x=x>>1;
            y=y>>1;
        }
        return ans;
    }
};