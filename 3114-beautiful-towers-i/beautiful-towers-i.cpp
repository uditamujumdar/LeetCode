class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n=heights.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int x=heights[i];
            long long sum=heights[i];
            for(int j=i-1;j>=0;j--){
                x=min(x, heights[j]);
                sum+=x;
            }
            x=heights[i];
            for(int j=i+1;j<n;j++){
                x=min(x, heights[j]);
                sum+=x;
            }
            if(sum>ans){
                ans=sum;
            }
        }

        return ans;
    }
};