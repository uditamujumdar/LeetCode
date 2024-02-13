class Solution {
public:
    // KMP ALGORITHM :- vector<int> V = KMP (string s1, string s2).
    vector<int> buildLPS(const string& p) {
        int m = p.length();
        vector<int> l(m, 0);
        int len = 0;
        for (int i = 1; i < m;) {
            if (p[i] == p[len]) {
                len++;
                l[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = l[len - 1];
                else {
                    l[i] = 0;
                    i++;
                }
            }
        }
        return l;
    }
    vector<int> KMP(const string& t, const string& p) {
        int n = t.length();
        int m = p.length();
        vector<int> a, lps = buildLPS(p);
        int i = 0, j = 0;
        while (i < n) {
            if (p[j] == t[i]) {
                j++; i++;    
            }
            if (j == m) {
                a.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && p[j] != t[i]) {
                if (j != 0) j = lps[j - 1];    
                else i++;    
            }
        }
        return a;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pat) {
        string s="";
        string t="";

        for(int i=0;i<pat.size();i++){
            if(pat[i]==1){
                s+='a';
            }
            if(pat[i]==0){
                s+='b';
            }
            if(pat[i]==-1){
                s+='c';
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                t+='b';
            }
            if(nums[i+1]<nums[i]){
                t+='c';
            }
            if(nums[i+1]>nums[i]){
                t+='a';
            }
        }

        vector<int>v=KMP(t, s);
        return v.size();
    }
};