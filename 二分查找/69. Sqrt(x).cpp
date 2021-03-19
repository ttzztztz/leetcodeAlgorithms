class Solution {
public:
    int mySqrt(int x) {
        double l = 0.0, r = x;
        while (abs(r - l) > 1e-9) {
            const double mid = (l + r) / 2.0;
            if (mid * mid <= 1.0 * x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return floor(l + 1e-9);
    }
};
