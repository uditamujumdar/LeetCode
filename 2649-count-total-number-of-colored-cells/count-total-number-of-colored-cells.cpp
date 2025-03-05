class Solution {
public:
    long long coloredCells(int n) {
        if(n==1){
            return 1;
        }
        long long ans=1;
        long long i=4;
        for(int j=2;j<=n;j++){
            ans+=i;
            i+=4;
        }

        return ans;
    }
};