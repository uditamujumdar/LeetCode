class Solution {
public:
    vector<int> f(int x){
        vector<int>v;
        while(x>0){
            v.push_back(x%10);
            x/=10;
        }
        return v;
    }

    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        vector<int>v=f(x);
        int i=0, j=v.size()-1;
        while(i<=j){
            if(v[i]!=v[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};