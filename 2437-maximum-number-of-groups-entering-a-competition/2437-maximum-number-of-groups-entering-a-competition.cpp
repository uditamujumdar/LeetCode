class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        
        int n=grades.size();
        int ans=0;

        for(int i=1;i<=n;i++){
            n-=i;
            if(n<0){
                break;
            }
            else{
                ans++;
            }
        }

        return ans;
    }
};