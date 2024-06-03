class Solution {
public:
    bool check(vector<int>&v, int days, int wt){
        int cnt=0;
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(sum>wt){
                cnt++;
                sum=0;
                i--;
            }
        }
        if(sum>0)cnt++;
        return cnt<=days;
    }

    int shipWithinDays(vector<int>& w, int days) {
        int i=*max_element(w.begin(),w.end());
        int j=accumulate(w.begin(), w.end(),0);

        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=check(w,days,mid);

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