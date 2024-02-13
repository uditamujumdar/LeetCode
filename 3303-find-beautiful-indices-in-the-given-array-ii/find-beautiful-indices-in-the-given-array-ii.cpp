class Solution {
public:
    // KMP ALGORITHM :- vector<int> V = KMP (string s1, string s2).
    vector<int> buildLPS(const string& pattern) {
        int m = pattern.size();
        vector<int>lps(m, 0);
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while(i < m){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> KMP(const string& text, const string& pattern) {
        vector<int>lps = buildLPS(pattern);
        int n = text.size();
        int m = pattern.size();
        vector<int> matches;
        int i = 0, j = 0;
        while (i < n) {
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            if(j == m){
                matches.push_back(i - j);
                j = lps[j - 1];
            }
            else if(i < n && text[i] != pattern[j]){
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
        }
        return matches;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>av=KMP(s, a);
        vector<int>bv=KMP(s, b);

        vector<int>ans;
        int i=0, j=0;
        while(i<av.size() && j<bv.size()){
            int diff=abs(av[i]-bv[j]);
            if(diff<=k){
                ans.push_back(av[i]);
                i++;
            }
            else if(bv[j]>av[i]){
                i++;
            }
            else{
                j++;
            }
        }

        return ans;
    }
};