#define ll long long
class Solution {
public:
    bool f(ll mid, vector<int>&start, int d){
        ll prev=(ll)start[0];
        for(int i=1;i<start.size();i++){
            ll curr=max(prev+mid, (ll)start[i]);
            if(curr>(ll)start[i]+d){
                return false;
            }
            prev=curr;
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        int n=start.size();
        sort(start.begin(), start.end());
        ll i=0, j=(ll)start[n-1]+d-(ll)start[0];

        while(i<=j){
            ll mid=i+(j-i)/2;
            bool flag=f(mid,start,d);

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