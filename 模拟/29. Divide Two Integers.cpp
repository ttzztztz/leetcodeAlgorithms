class Solution {
public:
    int divide(int dividend, int divisor) {
        double a = dividend, b = divisor;
        long long x = a / b;
        if (numeric_limits<int>::min() <= x && x <= numeric_limits<int>::max()) {
            return x;
        } else {
            return numeric_limits<int>::max();
        }
    }
};
