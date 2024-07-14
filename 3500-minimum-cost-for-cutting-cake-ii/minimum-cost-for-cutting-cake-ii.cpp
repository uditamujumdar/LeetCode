class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hor, vector<int>& ver) {
        sort(hor.begin(),hor.end(),greater<int>());
        sort(ver.begin(),ver.end(),greater<int>());
        
        long long i=0,j=0,h=1,v=1,ans=0;
        while(i<m-1 && j<n-1){
            if(hor[i]>=ver[j]){
                ans+=hor[i]*v;
                h++;
                i++;
            }
            else{
                ans+=ver[j]*h;
                v++;
                j++;
            }
        }
        while(i<m-1){
            ans+=hor[i]*v;
            i++;
        }
        while(j<n-1){
            ans+=ver[j]*h;
            j++;
        }
        
        return ans;
    }
};