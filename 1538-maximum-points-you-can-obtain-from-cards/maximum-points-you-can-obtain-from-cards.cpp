class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int ans=0;

        //first k
        for(int i=0;i<k;i++){
            ans+=card[i];
        }

        int curr=ans;
        //remove last visited element, add non visited element
        for(int i=k-1;i>=0;i--){
            curr-=card[i];
            curr+=card[n-k+i];
            ans=max(ans, curr);
        }
        return ans;
    }
};
//woahhh