class Solution {
public:
    int fastPow(long long a, int b) {
        long long result = 1, base = a;
        const int MOD = 1e9+7;
        
        while (b) {
            if (b & 1) {
                result *= base;
                result %= MOD;
            }
            
            base *= base;
            base %= MOD;
            
            b >>= 1;
        }
        return result % MOD;
    }
    int countOrders(int n) {
        const int MOD = 1e9+7;
        long long answer = 1;
        
        for (int i = 1; i <= 2 * n; i++) answer = (answer * i) % MOD;
        long long reverse_x = fastPow(fastPow(2, n), MOD - 2);
        answer *= reverse_x;
        answer %= MOD;
        
        return answer % MOD;
    }
};
