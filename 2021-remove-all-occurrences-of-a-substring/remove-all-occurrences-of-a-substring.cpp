class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0,j=0;
        int p=part.length();

        while(j<s.length()){
            if(j-i+1<p){
                j++;
            }
            else if(j-i+1==p){
                if(s.substr(i,p)==part){
                    s.erase(i,p);
                    i=0,j=0;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        return s;
    }
};