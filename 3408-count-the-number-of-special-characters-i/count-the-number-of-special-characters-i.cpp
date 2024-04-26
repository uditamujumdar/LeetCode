class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        unordered_map<char,bool>mp;

        for(auto it: word){
            mp[it]=false;
        }

        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        for(auto i: word){
            if(mp[i]==false){
                mp[i]=true;
                if(i>='a'&&i<='z'){
                    if(mp.find(i-32)!=mp.end()){
                        mp[i-32]=true;
                        ans++;
                    }
                }
                else{
                    if(mp.find(i+32)!=mp.end()){
                        mp[i+32]=true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};