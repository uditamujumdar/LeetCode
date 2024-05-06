class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans=0;
        int i=0;
        int j=0;

        while(i<t.size() && j<s.size()){
            if(t[i]==s[j]){
                i++;
            }
            j++;
        }

        return t.size()-i;
    }
};