class Solution {
public:
    bool f(long long mid, vector<int>&v, int cars){
        long long car=0;
        for(int i=0;i<v.size();i++){
            long long maxi=sqrt(mid/v[i]);
            car+=maxi;
        }
        return car>=cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        sort(ranks.begin(), ranks.end());
        long long i=0;
        long long j=(long long)cars*cars*ranks.back();

        while(i<=j){
            long long mid=i+(j-i)/2;
            bool flag=f(mid, ranks, cars);
            if(flag){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};