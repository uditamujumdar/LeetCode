class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        vector<int>v;
        int n=c.size();
        if(n&1){
            return {};
        }
        map<int,int>mp;
        for(auto it: c){
            mp[it]++;
        }
        sort(c.begin(), c.end());

        for(int i=0;i<n;i++){
            if(mp.find(c[i])!=mp.end() && mp.find(c[i]*2)!=mp.end()){
                if(c[i]==0){
                    if(mp[0]>=2 && mp[0]%2==0){
                        v.push_back(0);
                        mp[0]-=2;
                    }
                }
                else{
                    v.push_back(c[i]);
                    mp[c[i]*2]--;
                    mp[c[i]]--;
                    if(mp[c[i]]==0)mp.erase(c[i]);
                    if(mp[c[i]*2]==0)mp.erase(c[i]*2);
                }
            }
        }
        if(v.size()==n/2){
            return v;
        }
        return {};
    }
};