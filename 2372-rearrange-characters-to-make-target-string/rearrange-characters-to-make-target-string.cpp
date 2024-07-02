class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int>mp1,mp2;
        for(auto it: s){
            mp1[it]++;
        }
        for(auto it: target){
            mp2[it]++;
        }

        int ans=1e9;
        for(int i=0;i<target.size();i++){
            ans=min(ans, mp1[target[i]]/mp2[target[i]]);
        }

        return ans;
    }
};