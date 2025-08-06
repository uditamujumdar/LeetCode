class Solution {
public:
    int mySqrt(int x) {
        long long i=1, j=x;
        while(i<=j){
            long long mid=i+(j-i)/2;
            if(mid*mid<=x){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return j;
    }
};