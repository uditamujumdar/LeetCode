class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        if(bills[0]!=5){
            return false;
        }
        int five=1, ten=0;
        for(int i=1;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five==0){
                    return false;
                }
                ten++;
                five--;
            }
            else{
                if(five>=1 && ten>=1){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};