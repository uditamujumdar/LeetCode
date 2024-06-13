#define ll long long
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
       vector<long long>jam;
        int n=nums.size();
        vector<long long>pref(n,0);
        sort(nums.begin(),nums.end());
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
        for(auto &it:queries)
        {
            long long ind=lower_bound(nums.begin(),nums.end(),it)-nums.begin();

            if(ind==nums.size() || ind==0)
            {
                jam.push_back(abs((long long)((long long)n*(long long)it)-pref[n-1]));
            }
            else 
            {
                int a=abs((pref[n-1]-pref[ind-1])-(n-ind)*it);
                int b=abs((pref[ind-1])-((ind)*it));
                cout<<a<<" "<<b<<endl;
               long long ans=abs((pref[n-1]-pref[ind-1])-(long long)(n-ind)*(long long)it)+abs((pref[ind-1])-((long long)(ind)*(long long)it));
               jam.push_back(ans);
            }
        }
        return jam;
    }
};
