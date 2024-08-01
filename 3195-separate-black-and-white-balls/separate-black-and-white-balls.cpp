class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int n=s.size();
        long long cnt=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')cnt++;
            else ans+=cnt;
        }
        return ans;
    }
};