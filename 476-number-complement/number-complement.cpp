class Solution {
public:
    int countbits(int n){
        int count=0;
        while(n>0){
            n=n>>1;
            count++;
        }

        return count;
    }
    
    int findComplement(int num) {
        int i=0;
        while(i<countbits(num)){
            num=num^(1<<i);
            i++;
        }

        return num;
    }
};