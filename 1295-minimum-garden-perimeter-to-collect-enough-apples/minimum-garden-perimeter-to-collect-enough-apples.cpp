class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long i=0, j=1e5;

        while(i<=j){
            long long mid=i+(j-i)/2;
            long long val=(2*mid)*(mid+1)*(2*mid+1);

            if(val>=neededApples){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return 8*i;
    }
};