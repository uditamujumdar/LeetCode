class Solution {
public:
    bool f(int mid, vector<int>& p, int h){
        long long cnt=0;
        for(int i=0;i<p.size();i++){
            cnt+=(p[i]/mid);
            if(p[i]%mid!=0){
                cnt++;
            }
        }
        return cnt<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int i=1, j=*max_element(piles.begin(), piles.end());
        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=f(mid, piles, h);
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