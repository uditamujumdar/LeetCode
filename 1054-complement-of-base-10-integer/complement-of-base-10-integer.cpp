class Solution {
public:
    int countbits(int n){
        int cnt=0;
        while(n!=0){
            cnt++;
            n=n>>1;
        }

        return cnt;
    }

    int bitwiseComplement(int n) {
        int c=countbits(n);
        int mask=1;
        for(int i=1;i<=c-1;i++){
            mask=mask|(1<<i);
        }

        return mask^n;
    }
};