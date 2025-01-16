class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=left.size();
        int r=right.size();
        int max1=-1, max2=-1;
        for(int i=0;i<l;i++){
            max1=max(max1, left[i]);
        }
        for(int i=0;i<r;i++){
            max2=max(max2, n-right[i]);
        }

        return max(max1, max2);
    }
};