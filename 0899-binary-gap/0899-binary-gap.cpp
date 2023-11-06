class Solution {
public:
    int countbits(int n){
        int count=0;
        while(n!=0){
            count++;
            n=n>>1;
        }
        return count;
    }

    int binaryGap(int n) {
        int count=countbits(n);
        vector<int>v;
        
        for(int i=0;i<count;i++){
            int x=n&1;
            n=n>>1;

            if(x==1)
            v.push_back(i);
        }

        int maxi=0;
        for(int i=0;i<v.size()-1;i++){
            int d=v[i+1]-v[i];
            maxi=max(maxi, d);
        }

        return maxi;
    }
};