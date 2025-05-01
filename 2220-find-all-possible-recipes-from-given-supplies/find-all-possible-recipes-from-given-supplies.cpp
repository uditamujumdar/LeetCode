class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        map<string,vector<string>>mp;
        set<string>st (sup.begin(), sup.end());
        map<string,int>indeg;

        for(int i=0;i<rec.size();i++){
            for(auto it: ing[i]){
                indeg[rec[i]]++;
                mp[it].push_back(rec[i]);
            }
        }

        vector<string>ans;
        queue<string>q;

        for(auto it: sup){
            q.push(it);
        }

        while(!q.empty()){
            string node=q.front();
            q.pop();

            for(auto it: mp[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }

        return ans;
    }
};