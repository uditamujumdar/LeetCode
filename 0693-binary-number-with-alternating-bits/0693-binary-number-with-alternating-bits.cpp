class Solution {
public:
    bool hasAlternatingBits(int n) {
        long x=(n^(n>>1));
        return !(x&(x+1));
    }
};