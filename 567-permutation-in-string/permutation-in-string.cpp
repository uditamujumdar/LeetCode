class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp, mp2;
        for(auto it: s1){
            mp2[it]++;
        }
        int k=s1.size(), n=s2.size();
        int i=0, j=0;

        while(j<n){
            mp[s2[j++]]++;
            if(j-i==k){
                if(mp==mp2){
                    return true;
                }
                mp[s2[i]]--;
                if(mp[s2[i]]==0){
                    mp.erase(s2[i]);
                }
                i++;
            }
        }
        return false;
    }
};