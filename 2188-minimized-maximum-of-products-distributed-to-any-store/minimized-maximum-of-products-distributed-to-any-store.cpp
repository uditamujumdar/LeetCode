class Solution {
public:
    bool check(int n, vector<int>&v, int mid){
        int cnt=0;
        for(int i=0;i<v.size();i++){
            cnt+=(v[i]/mid);
            if(v[i]%mid){
                cnt++;
            }
        }
        return cnt<=n;
    }

    int minimizedMaximum(int n, vector<int>& quan) {
        int m=quan.size();
        int i=1, j=*max_element(quan.begin(), quan.end());

        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=check(n,quan,mid);

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