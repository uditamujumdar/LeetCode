class Solution {
public:
    bool check(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {
        int n=s.length();
        int m=t.length();
        int ans=0;

        for(int i=0;i<n;i++){
            string p;
            for(int j=i;j<n;j++){
                p+=s[j];
                if(check(p)){
                    ans=max(ans, (int)p.length());
                }
            }
        }
        
        for(int i=0;i<m;i++){
            string p;
            for(int j=i;j<m;j++){
                p+=t[j];
                if(check(p)){
                    ans=max(ans, (int)p.length());
                }
            }
        }
        
        for(int i=0;i<n;i++){
            string p;
            for(int j=i;j<n;j++){
                p+=s[j];
                for(int k=0;k<m;k++){
                    string r;
                    for(int l=k;l<m;l++){
                        r+=t[l];
                        if(check(p+r)){
                            ans=max(ans, (int)p.length()+(int)r.length());
                        }
                    }
                }
            }
        }
        return ans;
    }
};