class Solution {
public:
int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0,e=0,o=0,cnt=0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum&1){
                o++;
                cnt++;
                cnt+=e%mod;
                cnt=cnt%mod;
            }
            else{
                e++;
                cnt+=o%mod;
                cnt=cnt%mod;
            }
        }
        return cnt%mod;
    }
};
