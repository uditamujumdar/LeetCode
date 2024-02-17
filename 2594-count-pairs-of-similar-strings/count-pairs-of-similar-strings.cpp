class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            string s=words[i];
            set<char>st;
            for(auto it: s){
                st.insert(it);
            }
            for(int j=i+1;j<n;j++){
                string t=words[j];
                bool flag=true;
                set<char>st2;
                for(auto it: t){
                    st2.insert(it);
                }
                if(st2.size()!=st.size()){
                    flag=false;
                }
                for(auto it: t){
                    if(st.find(it)==st.end()){
                        flag=false;
                    }
                }
                if(flag){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};