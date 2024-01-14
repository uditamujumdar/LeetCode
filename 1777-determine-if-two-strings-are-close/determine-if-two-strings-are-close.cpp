class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }

        map<char, int>mp1, mp2;

        for(auto it: word1){
            mp1[it]++;
        } 
        for(auto it: word2){
            mp2[it]++;
        }

        for(auto it: word1){
            if(mp2[it] == 0){
                return false;
            }
        }

        vector<int>v1, v2;
        for(auto it: mp1){
            v1.push_back(it.second);
        }
        for(auto it: mp2){
            v2.push_back(it.second);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return (v1 == v2);
    }
};