class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        map<string,int>mp;

        for(int i=0;i<n;i++){
            string temp="";
            temp+=s[i];
            mp[temp]++;
            for(int j=i+1;j<n;j++){
                temp+=s[j];
                mp[temp]++;
            }
        }
        int maxi=-1;
        for(auto it: mp){
            if(it.second>=3){
                string str=it.first;
                bool flag=true;
                for(int i=1;i<str.length();i++){
                    if(str[i]!=str[0]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    maxi=max(maxi,(int)str.length());
                }
            }
        }
        return maxi;
    }
};