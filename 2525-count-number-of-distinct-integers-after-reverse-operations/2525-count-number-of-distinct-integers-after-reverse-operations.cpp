class Solution {
public:
    int reverse(int n){
        int rev=0;
        while(n!=0){
            int dig=n%10;
            rev=rev*10+dig;
            n/=10;
        }

        return rev;
    }

    int countDistinctIntegers(vector<int>& nums) {
        vector<int>v;
        map<int, int>mp;

        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
            v.push_back(reverse(nums[i]));
        }

        for(int i=0;i<v.size();i++){
            mp[v[i]]++;
        }

        return mp.size();   
    }
};