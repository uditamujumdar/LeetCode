class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            if(i==0||i==n-1){
                int x=abs(nums[i]*n-sum);
                ans[i]=x;
            }
        }
        vector<int>pref(n, 0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        vector<int>suff(n, 0);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i];
        }

        for(int i=1;i<n-1;i++){
            int x=(nums[i]*(i+1)-pref[i]);
            int y=suff[i+1]-nums[i]*(n-i-1);
            // cout<<x<<" "<<y<<endl;
            ans[i]=x+y;
        }

        return ans;
    }
};