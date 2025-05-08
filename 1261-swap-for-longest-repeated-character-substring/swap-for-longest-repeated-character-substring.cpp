class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.size();
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[text[i]].push_back(i);
        }

        int ans=0;

        for(auto it: mp){
            char ch=it.first;
            vector<int>&v=it.second;
            
            int cnt=1;
            int prev=0;
            int maxi=0;

            for(int i=1;i<v.size();i++){
                if(v[i]-v[i-1]==1){
                    cnt++;
                }
                else if(v[i]-v[i-1]==2){
                    prev=cnt;
                    cnt=1;
                }
                else{
                    prev=0;
                    cnt=1;
                }
                maxi=max(maxi, cnt+prev);
            }
            if(v.size()>maxi){
                maxi++;
            }
            ans=max(ans, maxi);
        }

        return ans;
    }
};