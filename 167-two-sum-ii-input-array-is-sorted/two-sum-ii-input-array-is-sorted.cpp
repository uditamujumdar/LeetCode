class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int s=0, e=n-1;
        int i1, i2;

        while(s<e){
            if(target>numbers[s]+numbers[e]){
                s++;
            }
            else if(target<numbers[s]+numbers[e]){
                e--;
            }
            else{
                i1=s+1;
                i2=e+1;
                break;
            }
        }

        return {i1, i2};
    }
};