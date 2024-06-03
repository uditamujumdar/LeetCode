#define ll long long
class Solution {
public:
    bool check(vector<int>& bloom, int day, int m, int k){
        int cnt=0;
        int num=0;
        for(int i=0;i<bloom.size();i++){
            if(bloom[i]<=day){
                cnt++;
            }
            else{
                num+=(cnt/k);
                cnt=0;
            }
        }
        num+=(cnt/k);

        return num>=m;
    }

    int minDays(vector<int>& bloom, int m, int k) {
        int i=*min_element(bloom.begin(), bloom.end());
        int j=*max_element(bloom.begin(), bloom.end());
        int n=bloom.size();

        long long x=m*1ll*k*1ll;
        if(x>n){
            return -1;
        }

        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=check(bloom, mid, m, k);

            if(flag){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};