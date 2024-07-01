class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& List) {
        queue<pair<string,int>>q;
        q.push({begin, 1});

        set<string>st(List.begin(), List.end());
        st.erase(begin);

        while(!q.empty()){
            string s=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(s==end){
                return steps;
            }

            for(int i=0;i<s.size();i++){
                char org=s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        st.erase(s);
                        q.push({s, steps+1});
                    }
                }
                s[i]=org;
            }
        }

        return 0;
    }
};