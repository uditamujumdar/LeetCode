class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int ad) {
        int n=cap.size();
        vector<int>diff;
        int ans=0;
        for(int i=0;i<n;i++){
            if(rocks[i]>=cap[i]){
                ans++;
            }
            else{
                diff.push_back(cap[i]-rocks[i]);
            }
        }
        sort(diff.begin(),diff.end());

        for(int i=0;i<diff.size();i++){
            if(ad==0){
                break;
            }
            if(diff[i]<=ad){
                ad-=diff[i];
                ans++;
            }
        }
        return ans;
    }
};