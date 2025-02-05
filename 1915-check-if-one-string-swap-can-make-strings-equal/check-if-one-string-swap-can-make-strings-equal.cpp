class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        vector<int>v;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                v.push_back(i);
            }
        }
        if(cnt==0)return true;

        if(cnt!=2)return false;

        return s1[v[0]]==s2[v[1]] && s1[v[1]]==s2[v[0]];
    }
};