class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans=0;
        int n=nums.size();
        int m=target.size();

        string temp="";

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp+=nums[i];
                temp+=nums[j];

                if(temp==target && i!=j){
                    ans++;
                }

                temp="";
            }
        }

        return ans;
    }
};