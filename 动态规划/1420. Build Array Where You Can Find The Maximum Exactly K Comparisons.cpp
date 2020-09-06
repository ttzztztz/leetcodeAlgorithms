class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        N = n, M = m, K = k;
        memset(f, 0xff, sizeof f);
        return dfs(0, 0, 0);
    }
private:
    const int MOD = 1e9+7;
    long long f[55][105][55];
    int N, M, K;
    long long dfs(int n, int m, int k) {
        if (k > K) return 0;
        if (N == n) {
            return k == K;
        }
        if (f[n][m][k] != -1) return f[n][m][k];
        
        long long answer = 0;
        if (m != 0) {
            for (int p = 1; p <= m; p++) {
                answer += dfs(n + 1, m, k);
                answer %= MOD;
            }
        }
        
        for (int p = m + 1; p <= M; p++) {
            answer += dfs(n + 1, p, k + 1);
            answer %= MOD;
        }
        
        return f[n][m][k] = answer;
    }
};
