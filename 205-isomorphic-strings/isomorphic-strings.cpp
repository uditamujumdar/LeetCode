class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp, mp2;
        for(int i=0;i<s.length();i++){

        //check that mp should not be empty
        //also to check whether a character in s is already mapped to that in t
        //and whether that mapping is different from t[i]
        
        if(mp[s[i]]&& mp[s[i]]!=t[i]){
            return false;
        }
        if(mp2[t[i]]&& mp2[t[i]]!=s[i]){
            return false;
        }
        
        mp[s[i]]=t[i];
        mp2[t[i]]=s[i];

        }
        return true;
    }
};