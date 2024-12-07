class Solution {
public:
    bool f(int mid, vector<int>&v, int maxop){
        priority_queue<int>pq;
        for(auto it: v)pq.push(it);

        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            if(top<=mid){
                return true;
            }
            int cnt=top/mid;
            if(top%mid==0){
                cnt--;
            }
            if(maxop>=cnt){
                maxop-=cnt;
            }
            else{
                return false;
            }
        }
        if(pq.empty()){
            return true;
        }
        return false;
    }

    int minimumSize(vector<int>& nums, int maxOp) {
        int n=nums.size();
        int i=1, j=*max_element(nums.begin(),nums.end());

        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=f(mid, nums, maxOp);
            if(flag){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};