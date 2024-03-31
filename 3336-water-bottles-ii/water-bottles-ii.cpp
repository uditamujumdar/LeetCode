class Solution {
public:
    int maxBottlesDrunk(int num, int ex) {
        int sum = num;
        int empt = num;
        int a = 0;
        while(empt >= ex) {
            empt -= ex;
            a++;
            ex++;
            if(empt < ex) {
                sum += a;
                empt+= a;
                a = 0;
            }    
        }
        return sum;
    }
};