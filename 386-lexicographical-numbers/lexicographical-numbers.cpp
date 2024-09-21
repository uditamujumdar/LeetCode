class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        vector<string>s;
        for(int i=1;i<=n;i++){
            s.push_back(to_string(i));
        }
        sort(s.begin(), s.end());
        for(auto it: s){
            ans.push_back(stoi(it));
        }

        return ans;
    }
};