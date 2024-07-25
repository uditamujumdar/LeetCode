class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int n=tasks.size();
        map<long long, long long>mp;
        long long s=1;

        for(int i=0;i<n;i++){
            long long temp=max(s, mp[tasks[i]]+space+1);
            if(mp[tasks[i]]){
                s=temp;
            }
            mp[tasks[i]]=s;
            s++;
        }
        return s-1;
    }
};