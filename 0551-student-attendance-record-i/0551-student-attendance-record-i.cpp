class Solution {
public:
    bool checkRecord(string s) {
        int a=0, l=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A')a++;
        }

        if(a>=2) return false;
        
        for(int i=0;i<s.length()-1;i++){
            if(s[i+1]=='L'&& s[i]=='L')l++;
            if(s[i]!=s[i+1])l=0;

            if(l>=2)
            {
                return false;
            }
        }

        return true;
    }
};