class Solution {
public:
    void f(set<int>& v, int n){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                v.insert(i);
                v.insert(n/i);
            }
        }
    }

    int kthFactor(int n, int k) {
        set<int>v;
        f(v,n);

        if(v.size()<k){
            return -1;
        }
        int cnt=1;
        for(auto it: v){
            if(cnt==k){
                return it;
            }
            cnt++;
        }
        return -1;
    }
};