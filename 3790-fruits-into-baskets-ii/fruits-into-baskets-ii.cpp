class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int ans=0;
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] && mp[j]==0){
                    flag=false;
                    mp[j]=1;
                    break;
                }
            }
            if(flag)ans++;
        }

        return ans;
    }
};