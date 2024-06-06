class Solution {
public:
    int brokenCalc(int start, int target) {
        int ans=0;
        while(target>start){
            if(target%2==0){
                target/=2;
            }
            else{
                target+=1;
            }
            ans++;
        }

        return ans+start-target;
    }
};