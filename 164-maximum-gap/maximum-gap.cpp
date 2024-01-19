class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }

        if(n==2){
            return abs(nums[0]-nums[1]);
        }

        priority_queue<int>pq;
        for(auto it:nums){
            pq.push(it);
        }
        int maxi=INT_MIN;

        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            int y=pq.top();

            maxi=max(maxi, abs(x-y));
        }

        return maxi;
    }
};