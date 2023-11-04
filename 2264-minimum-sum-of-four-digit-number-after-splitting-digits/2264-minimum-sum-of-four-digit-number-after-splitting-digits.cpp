class Solution {
public:
    int minimumSum(int num) {
        vector<char>v;
        while(num!=0)
        {
            int dig=num%10;
            v.push_back(dig+'0');
            num=num/10;
        }
        sort(v.begin(),v.end());
        int num1=(v[0]-'0')*10+v[3]-'0';
        int nums2=(v[1]-'0')*10+v[2]-'0';

        return num1+nums2;
    }
};