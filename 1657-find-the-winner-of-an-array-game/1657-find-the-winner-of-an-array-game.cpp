class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int ans=arr[0];
        int count=0;
        int n=arr.size();

        for(int i=1;i<n;i++){
            if(ans>arr[i]){
                count++;
            }
            else{
                ans=arr[i];
                count=1;
            }

            if(count==k){
                break;
            }
        }        
        return ans;
    }
};