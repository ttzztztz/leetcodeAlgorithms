class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        
        double a = abs((minutes / 60.0 * 360.0) - ((hour + (minutes / 60.0)) / 12 * 360.0));
        if (a > 180.0) {
            a = 360.0 - a;
        }
        return a;
    }
};
