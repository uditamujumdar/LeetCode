class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        int count=0;
        for(int i=0;i<bank.size();i++){
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            //count of 1s in every row
            if(count>0){
                v.push_back(count);
            }
            count=0;
        }

        int n=v.size();
        if(n==0||n==1){
            return 0;
        }
        
        int ans=0; 

        for(int i=0;i<n-1;i++){
            ans+=v[i]*v[i+1];
        }
        return ans;
    }
};