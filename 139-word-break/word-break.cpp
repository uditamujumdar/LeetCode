class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        unordered_set<string> st(w.begin(), w.end());
        queue<int>q;
        int n=s.size();
        q.push(0);
        vector<bool>vis(n+1);

        while(!q.empty()){
            int ind=q.front();
            q.pop();
            if(ind==s.length()){
                return true;
            }
            for(int i=ind+1;i<=s.length();i++){
                if(!vis[i] && st.find(s.substr(ind, i-ind))!=st.end()){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return false;
    }
};