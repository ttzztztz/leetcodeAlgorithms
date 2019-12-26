class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int K, int N) {
        if (K == 1) {
            return N;
        }
        if (N == 0) {
            return 0;
        }

        if (dp[K][N] != -1) {
            return dp[K][N];
        }

        int left = 1, right = N;
        while (left < right) {
            const int middle = (left + right) >> 1;

            const int T1 = dfs(K - 1, middle - 1), T2 = dfs(K, N - middle);
            if (T1 < T2) {
                left = middle + 1;
            } else if (T1 > T2) {
                right = middle;
            } else {
                left = right = middle;
            }
        }

        int answer = min(
            max(dfs(K - 1, left - 1), dfs(K, N - left)),
            max(dfs(K - 1, right - 1), dfs(K, N - right))
        ) + 1;

        return dp[K][N] = answer;
    }
    int superEggDrop(int K, int N) {
        dp = vector<vector<int>>(K + 5, vector<int>(N + 5, -1));

        return dfs(K, N);
    }
};