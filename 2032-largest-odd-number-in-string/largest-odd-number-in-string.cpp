class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        int flag=0;
        int ind=0;
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')&1){
                flag=1;
                ind=i;
                break;
            }
        }

        string ans="";
        if(flag){
            for(int i=0;i<=ind;i++){
                ans+=num[i];
            }
        }

        return ans;
    }
};