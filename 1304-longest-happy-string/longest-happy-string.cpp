class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});

        while(!pq.empty()){
            int top=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            if(ans.size()>1 && (ans.back()==ch && ans[ans.size()-2]==ch)){
                if(pq.empty()){
                    break;
                }
                int top2=pq.top().first;
                char ch2=pq.top().second;
                pq.pop();
                ans+=ch2;
                top2--;
                if(top2>0)pq.push({top2,ch2});
                
                pq.push({top,ch});
            }
            else{
                ans+=ch;
                top--;
                if(top>0){
                    pq.push({top,ch});
                }
            }
        }
        return ans;
    }
};