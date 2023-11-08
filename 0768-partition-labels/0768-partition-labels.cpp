class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int n=s.size();

        map<char, int>mp;
        for(int i=0;i<n;i++){
            //last occurence of the char
            mp[s[i]]=i;
        }

        int i=0;
        int j;
        while(i<n){
            int maxi=mp[s[i]];
            int count=0;
            for(j=i;j<=maxi;j++){
                if(mp[s[j]]>maxi){
                    maxi=mp[s[j]];
                }
                count++;
            }
            i=j;
            ans.push_back(count);
        }

        return ans;
    }
};