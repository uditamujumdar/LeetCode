class Solution {
public:
int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>v;
        
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());

        long long ans=0;
        for(int i=left-1;i<right;i++){
            ans+=v[i]%mod;
            ans=ans%mod;
        }
        return ans;
    }
};