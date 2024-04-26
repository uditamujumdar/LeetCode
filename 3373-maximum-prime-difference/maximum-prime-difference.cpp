class Solution {
public:
    bool isprime(int n){
        if(n==1){
            return false;
        }
        if(n==2){
            return true;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>prime;
        for(int i=0;i<nums.size();i++){
            if(isprime(nums[i])){
                prime.push_back(i);
            }
        }
        sort(prime.begin(), prime.end());

        return prime[prime.size()-1]-prime[0];
    }
};