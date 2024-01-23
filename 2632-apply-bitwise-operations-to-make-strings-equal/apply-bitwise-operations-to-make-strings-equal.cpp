class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int t = 0, a = 0;
        for(auto c: s) a+=(c - '0');
        for(auto c: target) t+=(c - '0');
        if(a > 0 && t > 0 || a == 0 && t == 0) return true;
        return false;
    }
};