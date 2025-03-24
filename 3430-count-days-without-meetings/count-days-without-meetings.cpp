class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        vector<pair<int,int>>v;
        // int n=m.size();
        for (auto it: m){
            v.push_back({it[0], 1});
            v.push_back({it[1]+1,-1}); 
        }
        sort(v.begin(),v.end());

        int x=0;
        int anss=0;
        int z=1;
        for (auto it: v) {
            int st=it.first;
            int end=it.second;
            
            if (z<st && x==0){
                anss+=(st-z);
            }
            x+=end;
            z=st;
        }
        
        if(z<=days&&x==0){
            anss+=days-z+1;
        }

        return anss;
    }
};