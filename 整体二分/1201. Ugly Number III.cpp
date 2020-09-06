class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        const unsigned long long _n = n;
        unsigned long long left = 1, right = 1e18;
        
        while (left < right) {
            unsigned long long mid = (left + right) >> 1;
            
            const unsigned long long p = (mid / a) + (mid / b) + (mid / c) - mid / lcm(a, b) - mid / lcm(a, c) - mid / lcm(b, c) + mid / lcm(lcm(a, b), c);
            if (p >= _n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
private:
    unsigned long long gcd(unsigned long long a, unsigned long long b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
    unsigned long long lcm(unsigned long long a, unsigned long long b) {
        return a * b / gcd(a, b);
    }
};
