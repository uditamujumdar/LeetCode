class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i;
        for(i=0;i<n;i++){
            if(s[i]!=' '){
                break;
            }
        }
        bool flag=false;
        if(s[i]=='-'){
            i++;
            flag=true;
        }
        if(!flag && s[i]=='+'){
            i++;
        }
        long long ans=0;
        for(int j=i;j<n;j++){
            if(!(s[j]<='9' && s[j]>='0')){
                break;
            }
            ans=ans*10+(s[j]-'0');
            if(!flag && ans>INT_MAX){
                return INT_MAX;
            }
            if(flag && ans>INT_MAX){
                return INT_MIN;
            }
        }
        if(!flag){
            return ans;
        }
        return -1*ans;
    }
};