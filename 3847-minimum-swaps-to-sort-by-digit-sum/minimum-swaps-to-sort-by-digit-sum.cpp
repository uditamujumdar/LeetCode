class Solution {
public:
    int sum(int n){
        int ans=0;
        while(n>0){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, pair<int, int>>>v;
        for(int i=0;i<n;i++){
            v.push_back({sum(nums[i]), {nums[i], i}});
        }

        sort(v.begin(), v.end());

        int ans=0;
        for(int i=0;i<n;i++){
            int ind=v[i].second.second;
            if(ind!=i){
                ans++;
                swap(v[i], v[ind]);
                i--;
            }
        }

        return ans;
    }
};
//woahhh