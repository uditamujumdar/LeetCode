class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min, hr;

        min=6*minutes; 

        hr=0.5*minutes;
        hr+=(30*hour);

        double a1=abs(hr-min);
        double a2=360-abs(hr-min);

        if(a1<a2)return a1;
        return a2;
    }
};