class Solution {
public:
    long long f(int k, vector<int>& v){
        long long total=0;
        for(long long i=0;i<v.size();i++){
            total+=v[i]/k;
            if(v[i]%k){
                total++;
            }
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size();
        long long i=1;
        long long j=*max_element(piles.begin(), piles.end());
        long long ans=1e9;

        while(i<=j){
            long long mid=i+(j-i)/2;
            long long tot=f(mid,piles);
            if(tot<=h){
                ans=min(ans, mid);
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};