class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int count=INT_MIN;
        int element=0;
        for(auto it: mp){
            if(it.second>=count){
                count=it.second;
                element=it.first;
            }
        }

        return element;
    }
};