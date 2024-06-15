class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pro, vector<int>& cap) {
        int n=pro.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({cap[i], pro[i]});
        }

        priority_queue<int>profitpq;

        int ans=w;
        while(k--){
            while(!pq.empty() && pq.top().first<=ans){
                profitpq.push(pq.top().second);
                pq.pop();
            }
            if(profitpq.empty()){
                return ans;
            }
            ans+=profitpq.top();
            profitpq.pop();
        }
        return ans;
    }   
};