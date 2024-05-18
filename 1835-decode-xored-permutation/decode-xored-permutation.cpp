class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int x=0;
        int n=encoded.size();
        for(int i=1;i<=n+1;i++){
            x^=i;
        }
        
        for(int i=1;i<n;i+=2){
            x^=encoded[i];
        }
        
        vector<int>perm;
        perm.push_back(x);
        for(int i=0;i<n;i++){
            x^=encoded[i];
            perm.push_back(x);
        }
        return perm;
    }
};