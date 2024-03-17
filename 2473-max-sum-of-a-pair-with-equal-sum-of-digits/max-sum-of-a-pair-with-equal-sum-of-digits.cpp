class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        vector<vector<int>>v(82);

        for(auto it: nums){
            int s=digitsum(it);
            v[s].push_back(it);
        }

        // for(int i=0;i<81;i++){
        //     for(int j=0;j<v[i].size();j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<82;i++){
            sort(v[i].begin(), v[i].end());
        }
         
        int maxi=INT_MIN;

        for(int i=0;i<82;i++){
            int s=v[i].size();
            if(s>=2){
                long long sum=v[i][s-1]+v[i][s-2];
                if(sum>maxi){
                    maxi=sum;
                }
            }
        }

        // int maxi=INT_MIN;
        // for(auto it: v){
        //     if(it.second==2)
        //     maxi=max(it.first, maxi);
        // }

        if(maxi==INT_MIN)return -1;

        return maxi;
    }
};