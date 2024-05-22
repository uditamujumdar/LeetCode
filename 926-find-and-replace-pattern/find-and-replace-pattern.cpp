class Solution {
public:
    void f(string& s){
        char ch='a';
        unordered_map<char,char>mp;
        for(auto it: s){
            if(mp.find(it)==mp.end()){
                mp[it]=ch++;
            }
        }
        for(int i=0;i<s.length();i++){
            s[i]=mp[s[i]];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        f(pattern);

        for(auto it: words){
            string s=it;
            f(s);
            if(s==pattern){
                ans.push_back(it);
            }
        }
        return ans;
    }
};