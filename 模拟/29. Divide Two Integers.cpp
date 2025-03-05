class Solution {
public:
    int divide(int dividend, int divisor) {
        typedef long long ll;
        ll a = dividend, b = divisor;
        const ll int_min = numeric_limits<int>::min();
        const ll int_max = numeric_limits<int>::max();

        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        else if (divisor == -1) {
            if (int_max <= -a) return int_max;
            else if (-a <= int_min) return int_min;
            return -a;
        }

        const bool is_positive = !((a > 0) ^ (b > 0));
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        if (a < b) return 0;

        ll cnt = 0;
        while (a >= b) {
            ll cur = 1, sum = b;
            while (sum + sum <= a) {
                sum += sum;
                cur += cur;
            }
            cnt += cur;
            a -= sum;
        }

        if (is_positive) return cnt;
        return -cnt;
    }
};