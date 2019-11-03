const int MOD = 1000000007;

class Solution {
public:
    long long factor[205];
    long long dp[205][205];
    string str;
    long long dfs(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        long long answer = 0;
        if (str[i] == 'D') {
            answer = (answer + dfs(i + 1, j)) % MOD;
        }
        if (str[j - 1] == 'I') {
            answer = (answer + dfs(i, j - 1)) % MOD;
        }

        for (int k = i + 1; k <= j - 1; k++) {
            if (str[k - 1] == 'I' && str[k] == 'D') {
                answer = (answer + (dfs(i, k - 1) * dfs(k + 1, j) % MOD) * C(j - i, k - i) % MOD) % MOD;
            }
        }
        return dp[i][j] = answer % MOD;
    }

    void init() {
        factor[0] = factor[1] = 1;
        for (int i = 2; i <= 200; i++) {
            factor[i] = factor[i - 1] * i % MOD;
        }
    }
    long long fastPow(long long x, int y) {
        long long answer = 1;
        while (y) {
            if (y & 1) {
                answer = answer * x % MOD;
            }
            x = x * x % MOD;
            y >>= 1;
        }
        return answer;
    }
    long long inverse(int x) {
        return fastPow(x, MOD - 2) % MOD;
    }
    long long C(int n, int m) {
        if (m > n) {
            return 0;
        }

        return (factor[n] * inverse(factor[m]) % MOD) * inverse(factor[n - m]) % MOD;
    }
    int numPermsDISequence(string S) {
        const int N = S.size();
        memset(dp, 0xff, sizeof(dp));
        init();

        str = S;
        return dfs(0, N);
    }
};