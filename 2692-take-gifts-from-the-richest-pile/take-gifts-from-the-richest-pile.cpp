class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        priority_queue<int>pq;
        for(auto it: gifts){
            pq.push(it);
        }
        while(k--){
            int top=pq.top();
            pq.pop();
            int root=sqrt(top);
            pq.push(root);
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};