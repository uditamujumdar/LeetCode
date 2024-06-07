class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        vector<int>even,odd;
        sort(target.begin(), target.end());
        sort(nums.begin(), nums.end());

        for(auto it: target){
            if(it&1){
                odd.push_back(it);
            }
            else{
                even.push_back(it);
            }
        }

        unordered_map<long long,long long>mp;
        mp[2]=0, mp[-2]=0;
        int e=0, o=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                if(odd[o]>=nums[i]){
                    mp[2]+=(odd[o]-nums[i])/2;
                }
                else{
                    mp[-2]+=abs(odd[o]-nums[i])/2;
                }
                o++;
            }
            else{
                if(even[e]>=nums[i]){
                    mp[2]+=(even[e]-nums[i])/2;
                }
                else{
                    mp[-2]+=abs(even[e]-nums[i])/2;
                }
                e++;
            }
        }
        long long ans=0;
        for(auto it: mp){
            ans+=it.second;
        }

        return ans/2;
    }
};