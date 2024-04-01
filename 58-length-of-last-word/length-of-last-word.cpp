class Solution {
public:
    int lengthOfLastWord(string s) {
        int j;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                j=i;
                break;
            }  
        }
        
        int count=0;
        for(int i=j;i>=0;i--){
            if(s[i]==' ')
            break;

            else
            count++;
        }
        return count;
    }
};