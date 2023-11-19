class Solution {
public:
    long long minimumSteps(string s) {
        vector<int>occ;
        long long count=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                occ.push_back(i);
            }
        }
        
        int n=s.length()-1;
        
        if(occ.size()==0 || occ.size()==n+1)return 0;
        
        for(int i=occ.size()-1;i>=0;i--){
            count+=n-occ[i];
            n=n-1;
        }
        
        return count;
    }
};