class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<long long>ans(n, 0);
        
        vector<pair<long long, long long>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums1[i] , i});
        }
        sort(temp.begin(), temp.end());
        
        long long sum=0;
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        int last=temp[0].first;
        map<long long, long long>mp;

        for(int i=0;i<n;i++){
            int ind=temp[i].second;
            int num=temp[i].first;
            if(i-1>=0){
                if(temp[i-1].first!=num){
                    last=temp[i-1].first;
                    ans[ind]=sum;
                }
                else{
                    if(num==last){
                        ans[ind]=0;
                    }else{
                        ans[ind]=mp[last];
                    }
                }
            }
            if(pq.size()<k){
                sum+=nums2[ind];
                pq.push(nums2[ind]);
            }
            else{
                if(pq.top()<nums2[ind]){
                    sum-=pq.top();
                    pq.pop();
                    sum+=nums2[ind];
                    pq.push(nums2[ind]);
                }
            }
            mp[num]=sum;
        }

        return ans;
    }
};