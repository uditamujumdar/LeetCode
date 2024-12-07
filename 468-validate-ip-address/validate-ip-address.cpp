#define ll long long
class Solution {
public:
    bool f(char ch){
        if((ch>='0' && ch<='9') || (ch>='a' && ch<='f') || (ch>='A' && ch<='F')){
            return true;
        }
        return false;
    }
    string validIPAddress(string q) {
        int n=q.length();
        int d=0, dd=0;
        string fal="Neither";
        for(auto it: q){
            if(it=='.'){
                d++;
            }
            if(it==':'){
                dd++;
            }
        }
        if(d==3){
            if(dd>0)return fal;
            if(q[0]=='0'){
                return fal;
            }
            for(int i=1;i<n;i++){
                if((q[i-1]=='.' && q[i]=='0' && q[i+1]!='.') || (q[i-1]=='.'&&q[i]=='.')){
                    return fal;
                }
            }
            int num=0;
            for(int i=0;i<n;i++){
                if((q[i]!='.')&& !(q[i]>='0' && q[i]<='9')){
                    return fal;
                }
                if(q[i]=='.'){
                    if(num>255)return fal;
                    num=0;
                    continue;
                }
                num=num*10+(q[i]-'0');
                if(num>255){
                    return fal;
                }
            }
            if(q[n-1]=='.' || num>255){
                return fal;
            }
            return "IPv4";
        }
        else if(dd==7){
            if(d>0)return fal;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(q[i]==':'){
                    if(cnt<1 || cnt>4){
                        return fal;
                    }
                    cnt=0;
                }
                else{
                    cnt++;
                    if(!f(q[i])){
                        return fal;
                    }
                }
            }
            if(q[n-1]==':' || cnt<1 || cnt>4){
                return fal;
            }
            return "IPv6";
        }
        else{
            return fal;
        }
    }
};