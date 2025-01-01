class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        int n=a.size();
        vector<string>ans;

        map<string,vector<int>>mp;
        for(auto it: a){
            string t=it[1];
            int num=0;
            for(auto iter: t){
                num=num*10+(iter-'0');
            }
            mp[it[0]].push_back(num);
        }
        
        for(auto it: mp){
            vector<int>v=it.second;
            sort(v.begin(), v.end());
            int cnt=0;
            if(v.size()<3){
                continue;
            }
            for(int i=0;i<v.size()-2;i++){
                if(v[i+2]-v[i]<100){
                    cnt++;
                }
            }
            if(cnt>0){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};