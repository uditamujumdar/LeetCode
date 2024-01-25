class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;

        for(int i=0;i<n;i++){
            string s=words[i];
            reverse(s.begin(), s.end());
            for(int j=i+1;j<n;j++){
                string t=words[j];
                if(s==t){
                    ans++;
                }
            }
        }
        return ans;
    }
};