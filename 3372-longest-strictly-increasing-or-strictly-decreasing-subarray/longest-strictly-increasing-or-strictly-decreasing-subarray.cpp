class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1=0;
        int ans2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int cnt=0;
            for(int j=i;j<nums.size()-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            ans1=max(ans1,cnt+1);
        }
        for(int i=0;i<nums.size();i++)
        {
            int nct=0;
            for(int j=i;j<nums.size()-1;j++)
            {
                if(nums[j]<nums[j+1])
                {
                    nct++;
                }
                else
                {
                    break;
                }
            }
            ans2=max(ans2,nct+1);
        }
        cout<<ans1<<" "<<ans2<<endl;
        return max(ans1,ans2);
    }
};