class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        int n=dig.size();
        
        if(dig[n-1]!=9){
            dig[n-1]++;
            return dig;
        }
        
        dig[n-1]=0;
        int carry=1;

        for(int i=n-2;i>=0;i--){
            if(dig[i]+carry<=9){
                dig[i]+=carry;
                carry=0;
            }
            else{
                int x=dig[i]+carry;
                dig[i]=x%10;
                x/=10;
                carry=x;
            }
        }
        vector<int>ans;
        if(carry>0){
            ans.push_back(carry);
        }
        for(auto it: dig){
            ans.push_back(it);
        }
        return ans;
    }
};

//ya perhaps reason h.. mujhse nhii ho rhaa abb! 
//nhi ho rhaa yrr