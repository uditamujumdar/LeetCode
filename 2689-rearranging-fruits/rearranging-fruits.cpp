#define ll long long
class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());
        int n=b1.size();

        map<ll,ll>mp1, mp2;
        for(auto it: b1){
            mp1[it]++;
        }
        for(auto it: b2){
            mp2[it]++;
        }

        for(auto it: b1){
            ll freq=mp1[it]+mp2[it];
            if(freq&1)return -1;
        }
        for(auto it: b2){
            ll freq=mp1[it]+mp2[it];
            if(freq&1)return -1;
        }

        ll i=0, j=n-1, mini=min(b1[0], b2[0]);
        ll ans=0;
        while(i<n){
            while(i<n && mp1[b1[i]]<=mp2[b1[i]]){
                i++;
            }
            while(j>=0 && mp2[b2[j]]<=mp1[b2[j]]){
                j--;
            }

            if(i<n && j>=0){
                ll temp=min(2*mini, (ll)min(b1[i], b2[j]));
                ans+=temp;

                ll x=b1[i];
                ll y=b2[j];

                mp1[x]--;
                mp2[x]++;

                mp2[y]--;
                mp1[y]++;
            }

            i++;
            j--;
        }

        return ans;
    }
};