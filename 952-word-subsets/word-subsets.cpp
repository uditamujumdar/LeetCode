class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        map<char,int>maxi, m;
        for(int i=0;i<words2.size();i++){
            for(auto it: words2[i]){
                m[it]++;
            }
            for(char ch='a';ch<='z';ch++){
                maxi[ch]=max(maxi[ch], m[ch]);
            }
            m.clear();
        }

        for(int i=0;i<words1.size();i++){
            map<char,int>mp;
            for(auto it: words1[i]){
                mp[it]++;
            }
            bool flag=true;
            for(char ch='a';ch<='z';ch++){
                if(mp[ch]<maxi[ch]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};