class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq;

        for(auto it: nums){
            pq.push(it);
        }
        int i=k-1;
        while(i>0){
            pq.pop();
            i--;
        }
        return pq.top();
    }
};