class Solution {
public:
    long long maximumTotalSum(vector<int>& maxi) {
       long long ans=0;
       sort(maxi.begin(),maxi.end());
       reverse(maxi.begin(),maxi.end());
       int curr=1e9+1;

       for(int i=0;i<maxi.size();i++){
            curr=min(curr-1, maxi[i]);
            if(curr<=0){
                return -1;
            }
            ans+=curr;
        }

        return ans;
    }
};