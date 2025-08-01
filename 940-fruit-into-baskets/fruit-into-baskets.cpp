class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        map<int,int>mp;
        int i=0, j=0;
        int maxi=0;

        while(j<n){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            maxi=max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }
};