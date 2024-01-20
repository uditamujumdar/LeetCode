class Solution {
public:
    int splitNum(int num) {
        vector<int>v;

        while(num!=0){
            int d=num%10;
            v.push_back(d);
            num/=10;
        }

        sort(v.begin(), v.end());
        int n=v.size();
        int num1=0, num2=0;
        for(int i=0;i<n;i++){
            if(i&1){
                num2=num2*10+v[i];
            }
            else{
                num1=num1*10+v[i];
            }
        }

        return num1+num2;
    }
};