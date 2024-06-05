class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        string s=words[0];
        map<char,int>mp;
        for(auto it: s){
            mp[it]++;
        }

        for(int i=1;i<words.size();i++){
            unordered_map<char,int>mp2;
            string t=words[i];
            for(auto it: t){
                mp2[it]++;
            }

            for(auto it: mp){
                mp[it.first]=min(mp2[it.first], it.second);
            }
        }

        for(auto it: mp){
            string str="";
            str+=it.first;
            while(it.second>0){
                it.second--;
                ans.push_back(str);
            }
        }
        return ans;
    }
};