class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=1, j=sqrt(c);
        
        if(j*j==c){
            return true;
        }
        while(i<=j){
            long long prod=i*i+j*j;
            if(prod==c){
                return true;
            }
            else if(prod>c){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};