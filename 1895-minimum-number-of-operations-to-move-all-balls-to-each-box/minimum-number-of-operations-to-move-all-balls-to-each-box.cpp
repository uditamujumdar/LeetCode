class Solution {
public:
    vector<int> minOperations(string b) {
        int n=b.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(b[j]=='1'){
                    cnt+=abs(j-i);
                }
            }
            v.push_back(cnt);
        }

        return v;
    }
};