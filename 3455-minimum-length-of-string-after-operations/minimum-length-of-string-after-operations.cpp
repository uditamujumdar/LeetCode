class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        if(n<=2){
            return n;
        }
        
        map<char,int>mp;
        int len=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            len++;
            if(mp[s[i]]==3){
                len-=2;
                mp[s[i]]-=2;
            }
        }
        
        return len;
    }
};