class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        int m=s.length();
        vector<int>pref(m+1,0);
        vector<char>temp={'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 
        'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z'};

        for(int i=0;i<n;i++){
            int st=shifts[i][0];
            int end=shifts[i][1];
            int dir=shifts[i][2];

            if(dir==0){
                pref[st]--;
                pref[end+1]++;
            }
            else{
                pref[st]++;
                pref[end+1]--;
            }
        }

        for(int i=1;i<m;i++){
            pref[i]+=pref[i-1];
        }

        // for(auto it: pref){
        //     cout<<it<<" ";
        // }

        for(int i=0;i<m;i++){
            int curr=pref[i];
            if(curr<0){
                int ind=(s[i]-'a')+curr;
                ind=ind%26;
                ind=(ind+26)%26;
                s[i]=temp[ind];
            }
            else if(curr>0){
                int ind=(s[i]-'a')+curr;
                ind=ind%26;
                s[i]=temp[ind];
            }
        }
        return s;
    }
};