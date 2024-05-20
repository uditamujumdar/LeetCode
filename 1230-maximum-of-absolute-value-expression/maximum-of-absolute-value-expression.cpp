class Solution {
public:
    int f(vector<int>& v){
        int n=v.size();
        int maxi=v[0], mini=v[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi, v[i]);
            mini=min(mini, v[i]);
        }
        return maxi-mini;
    }

    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int> u(n,0), v(n,0), w(n,0), x(n,0);

        for(int i=0;i<n;i++){
            u[i]=arr1[i]+arr2[i]+i;
            v[i]=arr1[i]-arr2[i]+i;
            w[i]=arr1[i]+arr2[i]-i;
            x[i]=arr1[i]-arr2[i]-i;
        }

        int a=max(f(u), f(v));
        int b=max(f(w), f(x));

        return max(a,b);
    }   
};