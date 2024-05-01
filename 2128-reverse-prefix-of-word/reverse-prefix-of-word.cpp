class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans="";
        int ind=0;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                ind=i;
                break;
            }
        }
        string sub=word.substr(0, ind+1);
        reverse(sub.begin(), sub.end());
        ans+=sub;
        for(int i=ind+1;i<word.size();i++){
            ans+=word[i];
        }
        return ans;
    }
};