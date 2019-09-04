class Solution {
public:
    double myPow(double x, int n) {
        long long newN = n;
        bool negativeFlag = false;

        if (newN == 0) {
            return 1;
        } else if (n < 0) {
            newN *= -1;
            negativeFlag = true;
        }
        double base = 1, pow = x;
        while (newN) {
            if (newN & 1) {
                base *= x;
            }
            x *= x;
            newN >>= 1;
        }

        if (negativeFlag) {
            return 1.0 / base;
        } else {
            return base;
        }
    }
};