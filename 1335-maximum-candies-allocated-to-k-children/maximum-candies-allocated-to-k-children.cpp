#define ll long long
class Solution {
public:
    bool f(vector<int>&v, ll cand, ll k){
        ll cnt=0;
        for(int i=0;i<v.size();i++){
            cnt+=(v[i]/cand);
        }
        return cnt>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        ll i=1;
        ll j=*max_element(candies.begin(),candies.end());

        while(i<=j){
            ll mid=i+(j-i)/2;
            bool flag=f(candies,mid,k);

            if(flag){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return j;
    }
};