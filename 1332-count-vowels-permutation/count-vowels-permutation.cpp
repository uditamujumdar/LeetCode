#define ll long long 
class Solution {
public:
    int mod=1e9+7;
    vector<vector<ll>>dp;
    
    ll f(int ind, char prev, int n, vector<char>&v){
        if(ind==n){
            return 1%mod;
        }
        if(dp[ind][prev-'a']!=-1){
            return dp[ind][prev-'a']%mod;
        }
        ll cnt=0;
        for(int i=0;i<v.size();i++){
            if(prev=='z'){
                cnt+=f(ind+1, v[i], n, v)%mod;
            }
            else{
                if(prev=='a'){
                    if(v[i]=='e'){
                        cnt+=f(ind+1, v[i], n, v)%mod;
                    }
                }
                if(prev=='e'){
                    if(v[i]=='a'||v[i]=='i'){
                        cnt+=f(ind+1, v[i], n, v)%mod;
                    }
                }
                if(prev=='i'){
                    if(v[i]!='i'){
                        cnt+=f(ind+1, v[i], n, v)%mod;
                    }
                }
                if(prev=='o'){
                    if(v[i]=='i'||v[i]=='u'){
                        cnt+=f(ind+1, v[i], n, v)%mod;
                    }
                }
                if(prev=='u'){
                    if(v[i]=='a'){
                        cnt+=f(ind+1, v[i], n, v)%mod;
                    }
                }
            }
        }

        return dp[ind][prev-'a']=cnt%mod;
    }

    int countVowelPermutation(int n) {
        dp.resize(n, vector<ll>(26,-1));
        vector<char>vows={'a' , 'e' , 'i' , 'o' , 'u'};
        
        return f(0, 'z', n, vows);
    }
};