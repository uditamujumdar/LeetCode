class Solution {
public:
    long long maximumHappinessSum(vector<int>& happ, int k) {
        long long ans=0;
        sort(happ.begin(), happ.end());
        int dec=0;
        for(int i=happ.size()-1;i>=0;i--){
            if(happ[i]>dec){
                ans+=(happ[i]-dec);
            }
            dec++;
            k--;
            if(k==0){
                break;
            }
        }

        return ans;
    }
};