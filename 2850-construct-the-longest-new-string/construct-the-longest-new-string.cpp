class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans=0;
        if(x==y){
            ans+=((x+y+z)*2);
            return ans;
        }

        int mini=min(x,y);
        
        if(mini==x){
            y=x+1;
        }
        else{
            x=y+1;
        }

        ans+=((x+y+z)*2);
        return ans;
    }
};