class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour=hour%12;
        double tilli1=hour*5.0;
        tilli1+=minutes/12.0;
        double ans=abs(minutes-tilli1)*6;
        return min(ans,360-ans);
        
    }
};