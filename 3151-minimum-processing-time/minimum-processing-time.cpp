class Solution {
public:
    int minProcessingTime(vector<int>& pr, vector<int>& tasks) {
        int n=pr.size();
        int m=tasks.size();

        sort(tasks.begin(),tasks.end(),greater<int>());
        sort(pr.begin(), pr.end());

        int ans=INT_MIN;
        int i=0,j=0;
        int t=0;

        while(j<m){
            t=max(t, pr[i]+tasks[j]);
            j++;
            if(j!=0 && j%4==0){
                i++;
                ans=max(ans, t);
                t=0;
            }
        }
        return ans;
    }
};