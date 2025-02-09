class Solution {
public:
    vector<int> assignElements(vector<int>& gr, vector<int>& ele) {
        int n=gr.size();
        int m=ele.size();
        map<int,int>mp;
        vector<int>ans(n, -1);
        for(int i=0;i<m;i++){
            if(mp.find(ele[i])!=mp.end()){
                mp[ele[i]]=min(mp[ele[i]], i);
            }
            else{
                mp[ele[i]]=i;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j*j<=gr[i];j++){
                if(gr[i]%j==0 && mp.find(j)!=mp.end()){
                    ans[i]=min(((ans[i]>=0)?ans[i]:INT_MAX), mp[j]);
                }
                if(gr[i]%j==0 && mp.find(gr[i]/j)!=mp.end()){
                    ans[i]=min(((ans[i]>=0)?ans[i]:INT_MAX), mp[gr[i]/j]);
                }
            }
        }

        return ans;
    }
};