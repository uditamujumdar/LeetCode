class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& w) {
        set<char>st(allowed.begin(), allowed.end());

        int ans=0;

        for(int i=0;i<w.size();i++){
            string temp=w[i];
            bool flag=true;

            for(int j=0;j<temp.length();j++){
                if(st.find(temp[j])==st.end()){
                    flag=false;
                    break;
                }
            }

            if(flag) ans++;
        }

        return ans;
    }
};