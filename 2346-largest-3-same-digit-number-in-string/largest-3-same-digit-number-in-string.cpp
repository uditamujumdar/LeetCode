class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int n=num.size();
        int temp=-1;
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1]&&num[i+1]==num[i+2]){
                temp=max(temp, num[i]-'0');
            }
        }

        if(temp==-1) return ans;
        
        else{
            ans+=to_string(temp);
            ans+=to_string(temp);
            ans+=to_string(temp);

            return ans;
        }
    }
};