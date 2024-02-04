class Solution {
public:
    int totalFruit(vector<int>& v) {
        int i=0, j=0;
        int ans=INT_MIN;
        map<int,int>mp;

        if(v.size()<=2){
            return v.size();
        }

        while(j<v.size()){
            mp[v[j]]++;

            if(mp.size()<=2){
                ans=max(ans, j-i+1);
            }
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[v[i]]--;
                    if(mp[v[i]]==0){
                        mp.erase(v[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};