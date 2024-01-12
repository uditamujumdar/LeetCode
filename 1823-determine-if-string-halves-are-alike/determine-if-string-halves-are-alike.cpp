class Solution {
public:
    int vowels(string str){
        int cnt=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='a'||str[i]=='e'||str[i]=='o'||str[i]=='u'||str[i]=='i'){
                cnt++;
            }
        }
        return cnt;
    }

    bool halvesAreAlike(string s) {
        int n=s.length();
        string a="", b="";

        for(int i=0;i<n/2;i++){
            a+=tolower(s[i]);
        }
        for(int i=n/2;i<n;i++){
            b+=tolower(s[i]);
        }

        return vowels(a)==vowels(b);
    }
};