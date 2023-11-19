class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int a=s1.size(), b=s2.size(), c=s3.size();
        int i=0;
        int count=0;
        int x=min(a, min(b,c));

        while(i<x){
            if(s1[i]==s2[i] && s2[i]==s3[i]){
                i++;
                count++;
            }
            else{
                break;
            }
        }

        if(count==0){
            return -1;
        }

        return a+b+c-(3*count);
        
    }
};