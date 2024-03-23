class Solution {
    string make_string(queue<char>q){
        string ans="";
        while(!q.empty()){
            ans+=(char)q.front();
            q.pop();
        }
        return ans;
    }
public:
    string orderlyQueue(string s, int k) {
        if(k==1)
        {
            queue<char>q;
            int j=k;
            for(auto it:s)
            {
                q.push(it);
            }
            map<string,int>mp;
            while(!q.empty())
            {
                string l=make_string(q);
                char topo=q.front();
                q.pop();
                q.push(topo);
                mp[l]++;
                if(mp[l]==2)break;
            }
       vector<string>kl;
        for(auto it:mp)
        {
            kl.push_back(it.first);
        }
        return kl[0];
        }
        if(k>1)
        sort(s.begin(),s.end());

        return s;
    }
};