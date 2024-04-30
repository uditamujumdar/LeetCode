class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        priority_queue<int>pq;
        for(auto it: mp){
            pq.push(it.second);
        }

        while(pq.size()>=2){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            x--;
            y--;
            if(x)pq.push(x);
            if(y)pq.push(y);
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};