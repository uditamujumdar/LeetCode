class Solution {
public: 
    bool f(int n){
        map<int,int>mp;
        while(n>0){
            mp[n%10]++;
            n/=10;
        }
        for(auto it: mp){
            if(it.second!=it.first){
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        if(n==0){
            return 1;
        }
        if(n<10){
            return 22;
        }
        for(int i=n+1;i<=1666666;i++){
            if(f(i)){
                return i;
            }
        }
        return 1666666;
    }
};