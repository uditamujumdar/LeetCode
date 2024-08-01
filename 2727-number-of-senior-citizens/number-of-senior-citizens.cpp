class Solution {
public:
    int countSeniors(vector<string>& det) {
        int n=det.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int age=(det[i][11]-'0')*10+(det[i][12]-'0');
            if(age>60){
                cnt++;
            }
        }
        return cnt;
    }
};