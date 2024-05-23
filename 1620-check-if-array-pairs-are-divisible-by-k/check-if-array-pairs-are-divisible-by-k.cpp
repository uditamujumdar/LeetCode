class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        int cnt=0;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            int rem=(arr[i]%k +k)%k;
            if(rem==0){
                if(mp.find(rem)!=mp.end()){
                    cnt++;
                    mp[rem]--;
                    if(mp[rem]==0){
                        mp.erase(rem);
                    }
                }
                else{
                    mp[rem]++;
                }
            }
            else if(mp.find(k-rem)!=mp.end()){
                cnt++;
                mp[k-rem]--;
                if(!mp[k-rem])
                mp.erase(k-rem);
            }
            else
            mp[rem]++;
        }

        if(cnt>=n/2)return true;

        return false;
    }
};
