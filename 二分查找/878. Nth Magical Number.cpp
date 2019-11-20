class Solution {
public:
    long long f(const long long x, const long long A, const long long B, const long long lcm) {
        return (x / A) + (x / B) - (x / lcm);
    }
    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
    int nthMagicalNumber(int N, int A, int B) {
        const long long lcm = A / gcd(A, B) * B;
        const int MOD = 1e9 + 7;

        long long left = 0, right = 1e15;
        while (left <= right) {
            const long long middle = (left + right) >> 1;

            if (f(middle, A, B, lcm) < N) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return left % MOD;
    }
};