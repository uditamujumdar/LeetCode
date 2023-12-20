class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int ans=money;
        sort(prices.begin(), prices.end());

        int x=prices[0]+prices[1];
        if(x>ans){
            return ans;
        }
        else{
            return ans-x;
        }
    }
};