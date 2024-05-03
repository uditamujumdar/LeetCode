class Solution {
public:
    static bool cmp(int a, int b){
        string s=to_string(a);
        string t=to_string(b);
        return s+t>t+s;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans="";

        if(nums[0]==0){
            return "0";
        }
        for(int i=0;i<nums.size();i++){
            ans+=(to_string(nums[i]));
        }
        return ans;
    }
};