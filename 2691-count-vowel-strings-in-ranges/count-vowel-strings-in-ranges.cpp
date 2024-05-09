class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }

    bool check(string s){
        int n=s.length();
        if(isvowel(s[0]) && isvowel(s[n-1])){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>v;
        for(int i=0;i<words.size();i++){
            if(check(words[i])){
                v.push_back(i);
            }
        }

        vector<int>ans;

        for(auto it: queries){
            int x=it[0];
            int y=it[1];
            int cnt=0;
            for(auto i: v){
                if(i>=x&&i<=y){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};