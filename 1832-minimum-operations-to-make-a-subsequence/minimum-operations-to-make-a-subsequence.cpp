class Solution {
public:
    void bs(int i, int j, int x, vector<int>& ans){
        if(i==j){
            ans[i]=x;
            return;
        }
        int mid=i+(j-i)/2;
        if(ans[mid]<x){
            bs(mid+1,j,x,ans);
        }
        else{
            bs(i,mid,x,ans);
        }
    }

    int minOperations(vector<int>& tar, vector<int>& arr) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<tar.size();i++){
            mp[tar[i]]=i;
        }
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                int x=mp[arr[i]];
                if(ans.size()==0 || x>ans.back()){
                    ans.push_back(x);
                }
                else{
                    bs(0,ans.size()-1,x,ans);
                }
            }
        }
        return tar.size()-ans.size();
    }
};

//5->-1
//1->-1
//3->3

//6->2
//4->0
//8->