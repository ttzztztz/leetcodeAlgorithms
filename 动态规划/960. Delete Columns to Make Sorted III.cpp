class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> dp(105, 1);
        const int N = A.size(), M = A[0].size();

        int maxLen = 1;
        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                bool flag = true;
                for (int k = 0; k < N; k++) {
                    if (A[k][i] > A[k][j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    dp[j] = std::max(dp[j], dp[i] + 1);
                    maxLen = std::max(maxLen, dp[j]);
                }
            }
        }

        return M - maxLen;
    }
};