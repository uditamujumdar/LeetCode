class Solution {
public:
    int bs(vector<int>&arr, int n, int x){
        if(arr[0]>x){
            return 0;
        }
        int i=0, j=n-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==x){
                return mid;
            }
            else if(arr[mid]<x){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return i;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int pos=bs(arr,n,x);
        int i=pos-1, j=pos;
        vector<int>ans;

        while(k>0&&i>=0&&j<n){
            if(abs(x-arr[i])<=abs(x-arr[j])){
                ans.push_back(arr[i--]);
            }
            else{
                ans.push_back(arr[j++]);
            }
            k--;
        }

        while(k--){
            if(i<0){
                ans.push_back(arr[j++]);
            }
            else if(j>=n){
                ans.push_back(arr[i--]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};