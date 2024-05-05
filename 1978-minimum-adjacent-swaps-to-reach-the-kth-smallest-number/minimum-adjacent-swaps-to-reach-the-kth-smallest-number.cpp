class Solution {
public:
    int swapss(string s1, string s2){
        int n=s1.size();
        int i=0,j=0;
        int ans=0;

        while(j<n){
            i=j;
            while(s1[i]!=s2[j]){
                i++;
            }
            while(j<i){
                swap(s1[i],s1[i-1]);
                i--;
                ans++;
            }
            j++;
        }
        return ans; 
    }

    int getMinSwaps(string num, int k) {
        string s=num;
        
        while(k--){
            next_permutation(num.begin(), num.end());
        }

        return swapss(s,num);
    }
};