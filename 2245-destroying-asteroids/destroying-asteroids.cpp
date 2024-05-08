class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        long long m=mass;
        for(int i=0;i<ast.size();i++){
            if(m>=ast[i]){
                m+=ast[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};