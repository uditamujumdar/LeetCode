class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0, j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int miss=arr[mid]-(mid+1);
            if(miss<k){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return j+k+1;
    }
};