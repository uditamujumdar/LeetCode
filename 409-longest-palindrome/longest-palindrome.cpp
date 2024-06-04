class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto it: s){
            mp[it]++;
        }
        int c=0;

        for(auto it: mp){
            if(it.second>1){
                c+=it.second-(it.second%2);
            }
        }
        if(c<s.size()){
            c++;
        }
        return c;
    }
};