class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int>v;
        v.push_back(1);
        int num=2;
        while(v.size()<n){
            if(find(v.begin(), v.end(), k-num)==v.end()){
                v.push_back(num);
            }
            num++;
        }
        for(auto it: v){
            cout<<it<<endl;
        }
        int sum=accumulate(v.begin(), v.end(), 0);
        return sum;
    }
};