#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll, vector<ll>, greater<ll>>pq;
        pq.push(1);
        ll cnt=0;
        ll prev=0;
        ll ans=1;

        while(cnt<n){
            while(pq.top()==prev){
                pq.pop();
            }
            ans=pq.top();
            pq.pop();
            cnt++;
            prev=ans;

            pq.push(ans*2*1ll);
            pq.push(ans*3*1ll);
            pq.push(ans*5*1ll);
        }

        return ans;
    }
};