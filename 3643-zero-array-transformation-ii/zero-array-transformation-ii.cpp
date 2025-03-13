class Solution {
public:
    bool check(vector<int>&nums, vector<vector<int>>&que, int mid){
        int n=nums.size();
        vector<int>temp=nums;
        vector<int>diff(n+1, 0);

        for(int i=0;i<mid;i++){
            int l=que[i][0];
            int r=que[i][1];
            int val=que[i][2];

            diff[l]-=val;

            if(r+1<n){
                diff[r+1]+=val;
            }
        }

        int curr=0;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            temp[i]+=curr;
            if(temp[i]>0){
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& que) {
        int n=nums.size();
        int i=0, j=que.size();
        int ans=-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=check(nums, que, mid);

            if(flag){
                ans=mid;
                j=mid-1;
            }

            else{
                i=mid+1;
            }
        }
        return ans;
    }
};