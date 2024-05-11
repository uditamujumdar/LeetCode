class Solution {
public:
    vector<int> f(int n){
        vector<int>v(64, 0);
        int i=0;
        while(n>0){
            v[i]=n%2;
            n/=2;
            i++;
        }
        return v;
    }

    int minFlips(int a, int b, int c) {
        vector<int>ab=f(a);
        vector<int>bb=f(b);
        vector<int>cb=f(c);

        int ans=0;
        for(int i=0;i<64;i++){
            if( (ab[i]|bb[i]) ==cb[i]){
                continue;
            }
            else if(cb[i]==0){
                if(ab[i]==1 && bb[i]==1){
                    ans+=2;
                }
                else{
                    ans++;
                }
            }
            else if(cb[i]==1){
                if(ab[i]==0 && bb[i]==0){
                    ans++;
                }
            }
        }

        return ans;
    }
};