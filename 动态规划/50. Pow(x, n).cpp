class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0) return 1;

        if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }

        double base = x, ans = 1.0;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = ans * base;
            }

            base = base * base;
            n /= 2;
        }
        return ans;
    }
};