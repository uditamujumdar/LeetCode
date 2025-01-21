#define ll long long
class Solution {
public:
    vector<ll>fact;
    vector<ll>invfact;

    ll pow(ll base, ll exp, ll mod){
        ll res=1;
        while(exp>0){
            if(exp%2==1){
                res=res*base%mod;
            }
            base=base*base%mod;
            exp/=2;
        }
        return res;
    }


    ll C(int a, int b){
        if(a>=b){
            return fact[a] * invfact[a-b]%mod * invfact[b]%mod;
        }
        return 0;
    }


    int mod=1e9+7;
    int minMaxSums(vector<int>& nums, int k) {
        int n=nums.size();
        ll sum=0;        
        sort(nums.begin(), nums.end());
        fact.resize(n+1, 1);
        invfact.resize(n+1, 1);
        for(int i=1;i<=n;i++){
            fact[i]=fact[i-1]*i%mod;
            invfact[i]=pow(fact[i], mod-2, mod);
        }


        for(int kk=1;kk<=k;kk++){
        for(int i=0;i<n;i++){
            ll maxi=C(i, kk-1);
            ll mini=C(n-i-1, kk-1);
            sum=(sum%mod+(nums[i]*mini)%mod)%mod;
            sum=(sum%mod+(nums[i]*maxi)%mod)%mod;
        }
        }
        return sum;
    }
};