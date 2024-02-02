class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt=0;
        int i=0, j=0;
        map<char,int>mp;
        int k=3;

        while(j<s.length()){
            mp[s[j]]++;
            if(j-i+1==k){
                if(mp.size()==3){
                    cnt++;
                }
                mp[s[i]]--;

                if(mp[s[i]]==0){
                   mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }    
        return cnt;
    }
};