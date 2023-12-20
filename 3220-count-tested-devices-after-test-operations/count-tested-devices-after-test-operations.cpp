class Solution {
public:
    int countTestedDevices(vector<int>& bp) {
        int count=0;
        int n=bp.size();

        for(int i=0;i<n;i++){
            if(bp[i]>count)
            count++;
        }
        return count;
    }
};