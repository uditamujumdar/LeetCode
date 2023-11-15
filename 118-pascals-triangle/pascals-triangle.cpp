class Solution {
private:
vector<int> f(int n){
    vector<int>output;
    long long num=1;
    output.push_back(num);
    for(int i=1;i<n;i++){
        num=num*(n-i);
        num=num/i;
        output.push_back(num);
    }
    return output;
}
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(f(i));
        }
        return ans;
    }
};