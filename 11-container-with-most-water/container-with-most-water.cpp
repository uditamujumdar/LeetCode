class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        
        int i=0,j=n-1;
        int maxi=INT_MIN;
        int amt=0;

        while(i<=j){
            amt=(min(h[j],h[i]) * abs(j-i));
            maxi=max(amt, maxi);

            if(h[j]>h[i]){
                i++;
            }
            else{
                j--;
            }
        }

        return maxi;
    }
};