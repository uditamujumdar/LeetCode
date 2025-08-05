class Solution {
public:
    bool check(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }

    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0, j=0;
        int ans=0;
        int cnt=0, maxi=0;

        while(j<n){
            if(check(s[j])){
                cnt++;
            }
            while(j-i+1>k){
                if(check(s[i])){
                    cnt--;
                }
                i++;
            }
            maxi=max(maxi, cnt);
            j++;
        }

        return maxi;
    }
};