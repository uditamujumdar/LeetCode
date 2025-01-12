class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k){
            return false;
        }
        if(n==k){
            return true;
        }
        map<char,int>mp;
        for(auto it: s){
            mp[it]++;
        }
        int o=0, e=0;
        for(auto it: mp){
            if(it.second&1){
                o++;
            }
            else{
                e++;
            }
        }
        if(o>k){
            return false;
        }
        return true;
    }
};