class Solution {
public:
    int setbits(int n){
        int count=0;
        while(n!=0){
            count+=n&1;
            n=n>>1;
        }
        return count;
    }

    bool isprime(int n){
        if(n==2){
            return true;
        }
        if(n<2){
            return false;
        }
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int cnt=setbits(i);
            if(isprime(cnt)){
                ans++;
            }
        }

        return ans;
    }
};