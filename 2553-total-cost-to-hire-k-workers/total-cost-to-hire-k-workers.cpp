class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        long long ans=0;
        int n=costs.size();
        priority_queue<int, vector<int>, greater<int>>pq1, pq2;
        int i=0, j=n-1;

        while(k--){
            while(pq1.size()<cand && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<cand && j>=i) pq2.push(costs[j--]);

            int a=INT_MAX, b=INT_MAX;

            if(pq1.size()>0){
                a=pq1.top();
            }
            if(pq2.size()>0){
                b=pq2.top();
            }

            if(a<=b){
                ans+=a;
                pq1.pop();
            }
            else{
                ans+=b;
                pq2.pop();
            }
        }

        return ans;
    }
};