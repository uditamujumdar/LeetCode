class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();

        map<char, int>mp;
        for(int i=0;i<n;i++){
            mp[word[i]]++;
        }
        
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end(), greater<int>());

            int cnt=0;
            int m=1;
            int ans=0;
            for(auto it: v){
                if(cnt==8){
                    m++;
                    cnt=0;
                }
                ans+=(m*it);
                cnt++;
            }
            
            return ans;
    }
};