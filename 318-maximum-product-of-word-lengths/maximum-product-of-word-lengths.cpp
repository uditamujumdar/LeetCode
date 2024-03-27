class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxi=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            set<char>st;
            for(auto it: s){
                st.insert(it);
            }
            for(int j=i+1;j<words.size();j++){
                string t=words[j];
                bool flag=true;
                for(int k=0;k<t.length();k++){
                    if(st.find(t[k])!=st.end()){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    int tl=t.length();
                    int sl=s.length();
                    maxi=max(maxi, tl*sl);
                }
            }
        }
        return maxi;
    }
};