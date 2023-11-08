class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.size();
        bool flag1=true, flag2=true;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int i=0, j=0;
        while(i<n && j<n){
            if(s1[i]<s2[j]){
                flag1=false;
            }
            if(s2[j]<s1[i]){
                flag2=false;
            }
            i++;
            j++;
        }

        if(flag1||flag2){
            return true;
        }
        else{
            return false;
        }
    }
};