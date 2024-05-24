class Solution {
public:
    int u[26], v[26];
    int ans=0;
    void f(int ind, vector<string>& words, vector<int>& score){
        if(ind==words.size()){
            int x=0;
            for(int i=0;i<26;i++){
                if(v[i]>u[i])return;
                x+=score[i]*v[i];
            }
            ans=max(ans, x);
            return;
        }

        f(ind+1, words, score);
        for(auto it: words[ind]){
            v[it-'a']++;
        }
        f(ind+1, words, score);
        for(auto it: words[ind]){
            v[it-'a']--;
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(auto it: letters){
            u[it-'a']++;
        }
        f(0,words,score);
        return ans;
    }
};