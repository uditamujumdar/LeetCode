class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int maxi=0;
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());

        int i=0, j=n-1;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
                maxi=max(score, maxi);
            }
            else if(score>0){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                break;
            }
        }
        return maxi;
    }
};