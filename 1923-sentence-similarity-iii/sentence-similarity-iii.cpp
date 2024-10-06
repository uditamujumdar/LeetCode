class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size()){
            swap(s1,s2);
        }
        if(s1==s2){
            return true;
        }
        vector<string>v1, v2;
        string s="";
        for(auto it: s1){
            if(it==' '){
                if(s.size()!=0)
                v1.push_back(s);
                s="";
            }
            else{
                s+=it;
            }
        }
        v1.push_back(s);
        s="";
        for(auto it: s2){
            if(it==' '){
                if(s.size()!=0)
                v2.push_back(s);
                s="";
            }
            else{
                s+=it;
            }
        }
        v2.push_back(s);
        int n=v1.size(), m=v2.size();

        int i=0, j=0;
        int k=n-1, l=m-1;

        while(i<n && j<m){
            if(v1[i]==v2[j]){
                i++;
                j++;
            }
            else{
                break;
            }
        }

        while(k>=0 && l>=0){
            if(v1[k]==v2[l]){
                k--;
                l--;
            }
            else{
                break;
            }
        }

        if(j>l){
            return true;
        }
        return false;
    }
};