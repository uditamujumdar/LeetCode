class Solution {
public:
    int maxArea(vector<int>& he) {
        int n=he.size();
        int i=0, j=n-1;
        int maxi=-1;
        while(i<j){
            int l=j-i;
            int h=min(he[i],he[j]);
            maxi=max(maxi, h*l);

            if(he[i]<he[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};