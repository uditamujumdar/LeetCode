class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<int>c(n);

        int ind=0;
        int cnt=0;
        while(ind<=n-1){
            for(int i=0;i<=ind;i++){
                for(int j=0;j<=ind;j++){
                    if(a[i]==b[j]){
                    cnt++;
                    }
                }
            }

            c[ind]=cnt;
            ind++;
            cnt=0;
        }

        return c;
    }
};