class Solution {
public:
    bool static compare(pair<char, int>& n,pair<char, int>& m){
      return n.second > m.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp;
      for(auto it : s){
        mp[it]++;
      }

      vector<pair<char, int>> ans;
      for(auto it : mp){
        ans.push_back(it);
      }
      sort(ans.begin(), ans.end(), compare);

      string finalstr = "";
      for(auto it : ans){
        int temp = it.second;
        while(temp > 0){
          finalstr.push_back(it.first);
          temp--;
        }
      }

      return finalstr;
    }
};