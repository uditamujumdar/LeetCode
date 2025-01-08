class Solution {
public:
    bool check(string s, string t){
        if(s.length()>t.length()){
            return false;
        }
        int i=0,j=0;
        while(i<s.length()){
            if(s[i]!=t[j]){
                return false;
            }
            i++;
            j++;
        }
        
        i=s.length()-1, j=t.length()-1;
        while(i>=0){
            if(s[i]!=t[j]){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            for(int j=i+1;j<words.size();j++){
                string t=words[j];
                if(check(s,t)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};