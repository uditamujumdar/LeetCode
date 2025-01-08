class Solution {
public:
    void f(vector<int>&org, vector<int>&der){
        int n=org.size();
        for(int i=1;i<n-1;i++){
            if(der[i]==1){
                org[i+1]=1-org[i];
            }
            else{
                org[i+1]=org[i];
            }
        }
    }

    bool doesValidArrayExist(vector<int>& der) {
        int n=der.size();
        vector<int>org(n);
        if(n==1){
            if(der[0]==0){
                return true;
            }
            return false;
        }
        if(der[0]==0){
            bool f1=true, f2=true;
            org[0]=0;
            org[1]=0;
            f(org,der);

            if((org[0]^org[n-1])!=der[n-1]){
                f1=false;
            }

            org[0]=1;
            org[1]=1;
            f(org,der);

            if((org[0]^org[n-1])!=der[n-1]){
                f2=false;
            }
            if(!f1 && !f2){
                return false;
            }
        }

        else{
            bool f1=true, f2=true;
            org[0]=1;
            org[1]=0;
            f(org,der);
            if((org[0]^org[n-1])!=der[n-1]){
                f1=false;
            }

            org[0]=0;
            org[1]=1;
            f(org,der);
            if((org[0]^org[n-1])!=der[n-1]){
                f2=false;
            }

            if(!f1 && !f2){
                return false;
            }
        }
        return true;
    }
};
//1^1=0
//0^0=0
//1^0=1