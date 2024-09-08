class Solution {
public:
    string f(int n){
        string s="";
        if(n==0){
            return "0";
        }
        while(n>0){
            s+=to_string(n%2);
            n/=2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string convertDateToBinary(string date) {
        string ans="";
        int num=(date[3]-'0')+(date[2]-'0')*10+(date[1]-'0')*100+(date[0]-'0')*1000;
        string yr=f(num);

        num=(date[6]-'0')+(date[5]-'0')*10;
        string m=f(num);
        
        num=(date[9]-'0')+(date[8]-'0')*10;
        string d=f(num);

        ans=yr+'-'+m+'-'+d;

        return ans;
    }
};