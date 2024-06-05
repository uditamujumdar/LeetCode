class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size();
        vector<int>v(121,0);
        for(int i=0;i<n;i++){
            v[ages[i]]++;
        }
        int ans=0;

        for(int i=1;i<=120;i++){
            int x=v[i];
            for(int j=1;j<=120;j++){
                int y=v[j];
                if( !(j<=(0.5*i+7) || j>i )){
                    ans+=x*y;
                    if(i==j){
                        ans-=x;
                    }
                }
            }
        }
        return ans;
    }
};