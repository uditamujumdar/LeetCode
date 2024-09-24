class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi=0;
        set<string>st;

        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            string str="";
            for(auto it: s){
                str+=it;
                st.insert(str);
            }
        }

        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            string str="";
            for(auto it: s){
                str+=it;
                if(st.count(str)){
                    maxi=max(maxi, (int)str.size());
                }
            }
        }

        return maxi;
    }
};