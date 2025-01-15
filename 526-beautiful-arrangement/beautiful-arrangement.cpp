class Solution {
public:
    bool vis[16]={};
    int ans=0;
    int f(int n, int pos){
        if(pos>n){
            return ans++;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i] && (i%pos==0 || pos%i==0)){
                vis[i]=true;
                f(n, pos+1);
                vis[i]=false;
            }
        }
        return ans;
    }

    int countArrangement(int n) {
        if(n==1 || n==2 || n==3){
            return n;
        }
        return f(n, 1);
    }
};