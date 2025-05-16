class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int p=primes.size();
        if(n==1){
            return 1;
        }
        long long ugly[n+1];
        ugly[0]=0;
        ugly[1]=1;

        vector<pair<int,int>>vp;
        for(int i=0;i<p;i++){
            vp.push_back({primes[i], 1});
        }

        for(int i=2;i<=n;i++){
            long long next=LLONG_MAX;
            for(int j=0;j<p;j++){
                next=min(next, ugly[vp[j].second]*(long long)vp[j].first);
            }
            ugly[i]=next;

            for(int j=0;j<p;j++){
                if(next==ugly[vp[j].second]*(long long)vp[j].first){
                    vp[j].second++;
                }
            }
        }

        return ugly[n];
    }
};