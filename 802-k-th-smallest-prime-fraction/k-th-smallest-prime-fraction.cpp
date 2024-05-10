class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>ans;
        vector<pair<float,pair<int,int>>>v;

        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                float frac=(float)arr[i]/(float)arr[j];
                v.push_back({frac, {i,j}});
            }
        }
        sort(v.begin(), v.end());

        int i=v[k-1].second.first;
        int j=v[k-1].second.second;

        ans.push_back(arr[i]);
        ans.push_back(arr[j]);

        return ans;
    }
};