class KthLargest {
    private:
    vector<int>nums;
    int k;  
    priority_queue<int, vector<int>,greater<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->nums=nums;
        this->k=k;
        for(auto it: nums){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */