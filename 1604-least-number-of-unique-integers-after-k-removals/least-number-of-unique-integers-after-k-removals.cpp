class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int, int>mp;
        for(auto it: arr){
            mp[it]++;
        }
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto it: mp){
            pq.push(it.second);
        }

        int sum=0;
        while(!pq.empty()){
            // cout<<pq.top()<<" "<<sum<<endl;
            sum+=pq.top();
            pq.pop();
            if(sum>=k){
                break;
            }
        }
        if(sum>k){
            pq.push(-1);
        }
        return pq.size();
    }
};