class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int n=special.size();
        
        int maxi=max(special[0]-bottom, top-special[n-1]);
        int cnt=0;

        for(int i=0;i<n-1;i++){
            maxi=max(maxi, special[i+1]-special[i]-1);
        }

        return maxi;
    }
};