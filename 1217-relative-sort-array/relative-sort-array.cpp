class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto it: arr1){
            mp[it]++;
        }
        vector<int>ans;

        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
            mp.erase(arr2[i]);
        }

        for(auto it: mp){
            while(it.second){
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
};