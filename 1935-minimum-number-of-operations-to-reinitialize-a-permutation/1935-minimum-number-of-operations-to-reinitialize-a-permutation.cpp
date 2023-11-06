class Solution {
public:
    void func(vector<int> original, vector<int> &vec1, vector<int> &vec2, int &cnt, int n){

        int val=0;

        for(int i=0; i<n; i++)  {
            if(i%2==0)  {
                vec2[i] = vec1[i/2];
                val += abs(vec2[i]-original[i]);
            }
            else if(i%2==1) {
                vec2[i] = vec1[(n/2)+((i-1)/2)];
                val += abs(vec2[i]-original[i]);
            }
        }

        cnt++;

        if(val==0)  {
            return;
        }
        else {
            func(original,vec2,vec1,cnt,n);
        }

    }

    int reinitializePermutation(int n) {
        vector<int> vec1(n,0);
        for(int i=0; i<n; i++) vec1[i]=i;
        vector<int> vec2(n,0);
        int cnt = 0;

        func(vec1,vec1,vec2,cnt,n);

        return cnt;
    }
};