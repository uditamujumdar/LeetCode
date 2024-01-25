class Solution {
public:
    bool isprime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>ans;
        vector<int>output;

        for(int i=2;i<=n/2;i++){
            if(isprime(i) && isprime(n-i)){
                output.push_back(i);
                output.push_back(n-i);
                sort(output.begin(), output.end());
                ans.push_back(output);

                output.clear();
            }
        }
        return ans;
    }
};