class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        int n=c.size();
        vector<int>v=c;
        for(int i=0;i<k;i++){
            v.push_back(c[i]);
        }   
        int cnt=1;
        int ans=0;
        for(auto it: v){
            cout<<it<<" ";
        }

        for(int i=0;i<v.size()-1;i++){
            if(cnt==k){
                cnt--;
                ans++;
            }
            if(v[i]!=v[i+1]){
                cnt++;
            }
            else{
                cnt=1;
            }
        }
        return ans;
    }
};