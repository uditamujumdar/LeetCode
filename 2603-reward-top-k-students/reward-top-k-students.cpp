class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }

    vector<int> topStudents(vector<string>& pos, vector<string>& neg, vector<string>& rep, vector<int>& stud, int k) {
        int n=rep.size();
        map<string,int>mp, mn;
        for(auto it: pos){
            mp[it]++;
        }
        for(auto it: neg){
            mn[it]++;
        }

        vector<pair<int,int>>vp;
        vector<int>ans;

        for(int i=0;i<n;i++){
            int pnts=0;
            string s="";
            for(int j=0;j<rep[i].size();j++){
                if(rep[i][j]==' '){
                    if(mp.find(s)!=mp.end()){
                        pnts+=3;
                    }
                    else if(mn.find(s)!=mn.end()){
                        pnts--;
                    }
                    s="";
                }
                else{
                    s+=rep[i][j];
                }
            }
            if(s.size()>0){
                if(mp.find(s)!=mp.end()){
                    pnts+=3;
                }
                else if(mn.find(s)!=mn.end()){
                    pnts--;
                }
            }
            vp.push_back({pnts, stud[i]});
        }

        sort(vp.begin(), vp.end(), cmp);

        for(int i=0;i<k;i++){
            ans.push_back(vp[i].second);
        }

        return ans;
    }
};