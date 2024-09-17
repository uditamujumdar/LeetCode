class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>u,v;
        string s="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                u[s]++;
                s="";
            }
            else{
                s+=s1[i];
            }
        }
        u[s]++;
        s="";

        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                v[s]++;
                s="";
            }
            else{
                s+=s2[i];
            }
        }
        v[s]++;

        vector<string>ans;
        for(auto it: u){
            if(it.second==1 && v.find(it.first)==v.end()){
                ans.push_back(it.first);
            }
        }
        for(auto it: v){
            if(it.second==1 && u.find(it.first)==u.end()){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};