class Solution {
public:
    int f(string s, int k){
        if(s.length()==0){
            return 0;
        }
        
        map<char,int>mp;
        for(auto it: s){
            mp[it]++;
        }

        for(int i=0;i<s.length();i++){
            if(mp[s[i]]<k){
                int left=f(s.substr(0, i), k);
                int right=f(s.substr(i+1), k);
                return max(left, right);
            }
        }
        return s.length();
    }

    int longestSubstring(string s, int k) {
        int n=s.length();
        return f(s, k);
    }
};