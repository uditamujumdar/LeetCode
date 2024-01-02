class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp,mp2;
        for(auto i: nums)
        {
            mp[i]++;
        }
        bool t = true;
        vector<vector<int>> res;
        while(t)
        {
            vector<int > temp;
            t = false;
            mp2 = mp;
            for(auto i: mp2)
            {
                temp.push_back(i.first);
                mp[i.first]--;
                if(mp[i.first] == 0 ){
                    mp.erase(i.first);
                }
                t = true;
            }
            if(!t)
                break;
            res.push_back(temp);
        }
        return res;
    }
};