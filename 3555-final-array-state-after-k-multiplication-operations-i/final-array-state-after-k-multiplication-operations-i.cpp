class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        while(k--){
            int x=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            x*=mul;
            pq.push({x,ind});
        }

        while(!pq.empty()){
            nums[pq.top().second]=pq.top().first;
            pq.pop();
        }
        return nums;
    }
};