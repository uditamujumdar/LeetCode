class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<=2){
            return false;
        }
        bool flag=false;

        for(int i=0;i<n-2;i++)
        {
            if(arr[i]&1 && arr[i+1]&1 && arr[i+2]&1)
            {
                flag=true;
            }
        }
        return flag;
    }
};