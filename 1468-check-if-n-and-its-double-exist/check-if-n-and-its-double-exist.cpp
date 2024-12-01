class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mp;
        for(auto it: arr){
            mp[it]++;
        }
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++){
            if(mp.find(2*arr[i])!=mp.end()){
                if(arr[i]==0){
                    if(mp[0]>=2){
                        return true;
                    }
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
};