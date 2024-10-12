class Solution {
public:
    int minGroups(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(inter[0][1]);

        for(int i=1;i<inter.size();i++){
            if(pq.top()<inter[i][0]){
                pq.pop();
            }
            pq.push(inter[i][1]);
        }
        return pq.size();
    }
};