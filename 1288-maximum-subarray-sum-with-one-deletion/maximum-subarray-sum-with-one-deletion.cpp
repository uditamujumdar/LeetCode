class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>pref(n), suff(n);
        pref[0]=arr[0];
        suff[n-1]=arr.back();

        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1]+arr[i], arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1]+arr[i], arr[i]);
        }

        int ans=*max_element(pref.begin(), pref.end());

        for(int i=1;i<n-1;i++){
            ans=max(ans, pref[i-1]+suff[i+1]);
        }
        return ans;
    }
};