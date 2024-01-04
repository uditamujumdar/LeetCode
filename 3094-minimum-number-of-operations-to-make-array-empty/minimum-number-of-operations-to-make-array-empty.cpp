class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it:mp)
        {
            if(it.second==1)
            {
                return -1;
            }
        }
        int count=0;
        
        for(auto it:mp)
        {
            if(it.second%3==0)
            {
                count+=it.second/3;
            }
            else if(it.second%3!=0)
            {
                if(it.second%3==2)
                {
                    count+=(it.second-2)/3 + 1;
                }
                else if(it.second%3==1)
                {
                    count+=(it.second-4)/3+2;
                }
                else
                {
                    count+=it.second/2;
                }
            }
            else
            {
                count+=it.second/3;
            }
        }
        return count;
    }
};