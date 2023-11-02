class Solution {
public:
    int wateringPlants(vector<int>& v, int cap) {
        int steps=0;

        int temp=cap;
        for(int i=0;i<v.size();i++){
            if(v[i]<=temp){
                temp-=v[i];
                steps+=1;
            }
            else{
                temp=cap;
                temp-=v[i];
                steps+=(2*i+1);
            }
        }

        return steps;

    }
};