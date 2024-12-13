class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long score=0;
        vector<int>vis(n, 0);
        while(!pq.empty()){
            int top=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(vis[ind]==0){
                score+=top;
                vis[ind]=1;
                if(ind!=0){
                    vis[ind-1]=1;
                }
                if(ind!=n-1){
                    vis[ind+1]=1;
                }
            }
        }

        return score;
    }
};