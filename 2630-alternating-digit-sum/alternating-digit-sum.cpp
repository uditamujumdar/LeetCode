class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int>v;
        while(n!=0){
            int dig=n%10;
            v.push_back(dig);
            n/=10;
        }
        reverse(v.begin(), v.end());

        int sum=0;
        for(int i=0;i<v.size();i++){
            if(i&1){
                sum-=v[i];
            }
            else{
                sum+=v[i];
            }
        }
        return sum;
    }
};