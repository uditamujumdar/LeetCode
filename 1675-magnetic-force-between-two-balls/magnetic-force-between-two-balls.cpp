class Solution {
public:
    bool f(vector<int>&pos, int mid, int m){
        int cnt=1;
        int p=pos[0];
        for(int i=1;i<pos.size();i++){
            if(pos[i]-p>=mid){
                cnt++;
                p=pos[i];
            }
        }
        return cnt>=m;
    }

    int maxDistance(vector<int>& pos, int m) {
        int n=pos.size();
        sort(pos.begin(), pos.end());

        int i=0, j=pos[n-1];

        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=f(pos,mid,m);

            if(flag){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return j;
    }
};