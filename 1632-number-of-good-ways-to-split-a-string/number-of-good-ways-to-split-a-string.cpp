class Solution {
public:
    int numSplits(string s) {
        int cnt=0;
        int n=s.length();
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        unordered_map<char,int>st;
        for(int i=0;i<s.length();i++){
            st[s[i]]++;
            mp[s[i]]--;
            if(mp[s[i]]==0)mp.erase(s[i]);
            if(st.size()==mp.size())cnt++;
        }
        return cnt;
    }
};