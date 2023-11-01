class Solution {
public:
    int minBitFlips(int start, int goal) {
        //perform bitwise XOR on the two numbers 
        //then count the number of set bits

        int temp= start^goal;
        int ans=0;

        while(temp!=0){
            ans+=temp&1;
            temp=temp>>1;
        }

        return ans;
    }
};