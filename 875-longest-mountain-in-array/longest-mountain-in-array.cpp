class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3){
            return 0;
        }

        int maxi=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                int start=i, end=i;

                while(start>0 && arr[start]>arr[start-1]){
                    start--;
                }
                while(end<n-1 && arr[end]>arr[end+1]){
                    end++;
                }
                maxi=max(maxi, end-start+1);
                i=end;
            }
        }
        return maxi;
    }
};