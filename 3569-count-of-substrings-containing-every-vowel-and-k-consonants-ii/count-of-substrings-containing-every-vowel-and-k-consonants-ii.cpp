class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    long long f(string& word, int k){
        long long ans=0;
        int n=word.size();

        map<char,int>mp;
        int i=0, j=0, cnt=0;

        while(j<n){
            if(isVowel(word[j])){
                mp[word[j]]++;
            }
            else{
                cnt++;
            }
            while(cnt>k && mp.size()==5){
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(mp[word[i]]==0){
                        mp.erase(word[i]);
                    }
                }
                else{
                    cnt--;
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return f(word, k)- f(word, k-1);
    }
};