class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int>dq;

        for(int i=0;i<nums.size();i++){
            dq.push_back(nums[i]);
        }

        for(int i=1;i<=k;i++){
            int elem=dq.back();
            dq.pop_back();
            dq.push_front(elem);

        }

        nums.clear();
        while(!dq.empty()){
            int elem=dq.front();
            dq.pop_front();
            nums.push_back(elem);
        }
    }
};