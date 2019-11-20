class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        const int MOD = 1e9 + 7;
        const int lcm = A / gcd(A, B) * B;

        const int M = lcm / A + lcm / B - 1;
        const int p = N / M, q = N % M;

        long long answer = 1ll * p * lcm % MOD;

        if (q == 0) {
            return answer;
        }

        long long slot1 = A, slot2 = B;
        for (int i = 0; i < q - 1; i++) {
            if (slot1 <= slot2) {
                slot1 += A;
            } else {
                slot2 += B;
            }
        }

        answer = (answer + min(slot1, slot2)) % MOD;
        return answer;
    }

    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
};