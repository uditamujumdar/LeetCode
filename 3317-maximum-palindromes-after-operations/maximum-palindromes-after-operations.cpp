class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int ans=0;
        vector<int>freq(26),len(101);
        int n=words.size();
        int rem=0;
        for(int i=0;i<n;++i)
        {
            int m=words[i].size();
            for(int j=0;j<m;++j)
            {
                freq[words[i][j]-'a']++;
            }
            len[m]++;
            rem+=m;
        }

        int pairs=0;
        for(auto &x:freq) pairs+=(x/2);

        rem-=2*pairs;

        for(int i=1;i<=100;++i)
        {
            int cnt=len[i];
            if(cnt==0) continue;
            int len=i;
            if(len%2==0)
            {
                int one=len/2;
                int curr=pairs/one;
                int mn=min(cnt,curr);
                ans+=mn;
                pairs-=(one*mn);

                if(pairs==0) break;
            }
            else
            {
                int one=len/2;
                int curr=0;
                if(one>0) curr=pairs/one;
                int mn=min(cnt,curr);
                pairs-=(one*mn);

                if(len==1) mn=cnt;

                if(rem>=mn)
                {
                    ans+=mn;
                    rem-=mn;
                }
                else
                {
                    if(pairs==0) break;
                    ans+=rem;
                    mn-=rem;
                    rem=0;
                    int lost=(mn+1)/2;
                    ans+=mn;
                    pairs-=lost;
                    if(mn%2==1) rem++;
                }
            }    
        }
        return ans;
    }
};