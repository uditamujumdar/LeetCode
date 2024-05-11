#define ll long long
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n==2){
            return skill[0]*skill[1];
        }

        ll total=accumulate(skill.begin(), skill.end(), 0ll);
        ll sum=total/(n/2);
        if(total%(n/2)!=0){
            return -1;
        }

        vector<pair<ll,ll>>v;

        unordered_map<int,int>mp;
        for(auto it: skill){
            mp[it]++;
        }
        sort(skill.begin(), skill.end());

        for(int i=0;i<n/2;i++){
            int x=skill[i];
            if(mp.find(sum-x)==mp.end()){
                return -1;
            }
            else if(mp[sum-x]==0){
                return -1;
            }
            else{
                mp[sum-x]--;
                v.push_back({x, sum-x});
            }
        }

        ll prod=0;
        for(auto it: v){
            prod+=(it.first*it.second);
        }

        return prod;
    }
};