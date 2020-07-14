class Solution {
public:
    double angleClock(int hour, int minutes) {
        double small_pointer = (double) minutes / 12 + hour * 5;
        small_pointer -= floor(small_pointer/60.0) * 60.0;
        
        double angle = abs(small_pointer-minutes) * 6.0;
        
        if (angle > 180.0) return 360.0 - angle;
        return angle;
    }
};