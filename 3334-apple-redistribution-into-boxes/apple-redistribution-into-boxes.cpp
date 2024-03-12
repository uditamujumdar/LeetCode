class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        int sum=accumulate(apple.begin(), apple.end(), 0);
        int ans=0;
        sort(cap.begin(), cap.end());
        int i;
         
        for(i=cap.size()-1;i>=0;i--){
            ans+=cap[i];
            if(ans>=sum){
                break;
            }
        }
        return cap.size()-i;
    }
};