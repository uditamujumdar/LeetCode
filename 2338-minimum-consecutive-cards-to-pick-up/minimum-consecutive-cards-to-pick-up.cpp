class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX;
        int i=0,j=0;
        unordered_map<int,int>mp;

        while(j<cards.size()){
            mp[cards[j]]++;
            
            while(mp.size()<j-i+1){
                ans=min(ans, j-i+1);
                mp[cards[i]]--;
                if(mp[cards[i]]==0){
                    mp.erase(cards[i]);
                }
                i++;
            }
            j++;
        }

        return ans==INT_MAX?-1:ans;
    }
};