class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        int ans=0;

        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>='a'){
                mp[ch]=i+1;
            }
        }
        for(int i=word.size()-1;i>=0;i--){
            char ch=word[i];
            if(ch>='A'&&ch<='Z'){
                mp[ch]=i+1;
            }
        }

        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>='a'){
                if(mp[ch]!=0 && mp[ch-32]!=0 && mp[ch-32]>mp[ch]){
                    mp[ch]=0;
                    mp[ch-32]=0;
                    ans++;
                }
            }
            else{
                if(mp[ch]!=0 && mp[ch+32]!=0 && mp[ch]>mp[ch+32]){
                    mp[ch+32]=0;
                    mp[ch]=0;
                    ans++;
                }
            }
        }

        return ans;
    }
};