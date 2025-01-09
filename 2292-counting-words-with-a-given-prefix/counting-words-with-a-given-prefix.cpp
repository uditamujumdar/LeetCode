class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            string s=words[i];
            bool flag=true;
            int j=0, k=0;
            while(j<pref.length() && k<n){
                if(pref[j]==s[k]){
                    j++;
                    k++;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt;
    }
};
//ek ajanabee.. haseena se.. yu mulaqat.. ho gyi..