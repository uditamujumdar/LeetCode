class Solution {
public:
    vector<int> countMentions(int num, vector<vector<string>>& eve) {
        int n=eve.size();
        vector<int>ans(num);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(eve[i][0]=="OFFLINE"){
                int t=stoi(eve[i][1]);
                int id=stoi(eve[i][2]);
                mp[id].push_back(t);
            }
        }
        
        for(int i=0;i<n;i++){
            if(eve[i][0]=="MESSAGE"){
                if(eve[i][2]=="ALL"){
                    for(int j=0;j<num;j++){
                        ans[j]++;
                    }
                }
                else if(eve[i][2]=="HERE"){
                    for(int j=0;j<num;j++){
                        if(mp.find(j)==mp.end()){
                            ans[j]++;
                        }
                    }
                    int t=stoi(eve[i][1]);
                    for(auto it: mp){
                        int id=it.first;
                        bool flag=true;
                        for(auto iter: it.second){
                            if(t>=iter && t-iter<60){
                                flag=false;
                                break;
                            }
                        }
                        if(flag){
                            ans[id]++;
                        }
                    }
                }
                else{
                    stringstream ss(eve[i][2]);
                    string id;
                    while(ss>>id){
                        if(id.substr(0, 2)=="id"){
                            int userid=stoi(id.substr(2));
                            ans[userid]++;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};