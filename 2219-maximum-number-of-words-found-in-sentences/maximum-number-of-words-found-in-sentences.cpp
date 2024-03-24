class Solution {
public:
    int mostWordsFound(vector<string>& sent) {
        int maxi=INT_MIN;
        
        for(int i=0;i<sent.size();i++){
            string s=sent[i];
            int cnt=0;
            for(int j=0;j<s.size();j++){
                if(s[j]==' '){
                    cnt++;
                }
            }
            cnt++;
            maxi=max(maxi, cnt);
        }

        return maxi;
    }
};