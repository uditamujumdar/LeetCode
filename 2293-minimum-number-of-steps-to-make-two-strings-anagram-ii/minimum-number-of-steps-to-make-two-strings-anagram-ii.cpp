class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int>mp;
        for(auto it: s){
            mp[it]++;
        }

        int cnt=0;
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])==mp.end()){
                cnt++;
            }
            else{
                if(mp[t[i]]!=0)
                mp[t[i]]--;
                else
                cnt++;
            }
        }

        for(auto it: mp){
            cnt+=it.second;
        }

        return cnt;
    }
};