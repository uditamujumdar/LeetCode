class Solution {
public:
    int countset(int n){
        int count=0;
        while(n!=0){
            count+=n&1;
            n=n>>1;
        }

        return count;
    }


    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans;
        
        vector<pair<int, int>>v;
        
        for(int i=0;i<arr.size();i++){
            v.push_back({countset(arr[i]), arr[i]});
        }

        sort(v.begin(), v.end());

        for(auto it: v){
            ans.push_back(it.second);
        }

        return ans;
    }
};