class Solution {
public:
    unsigned long long calc(int n) {
        const int MOD = 1000000007;

        unsigned long long answer = 0;
        unsigned long long C[2 * n + 1][2 * n + 1];

        for (int i = 1; i <= 2 * n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }

        return (C[2 * n][n] - C[2 * n][n - 1] + MOD) % MOD;
    }

    int numberOfWays(int num_people) {
        const int MOD = 1000000007;

        return calc(num_people / 2) % MOD;
    }
};