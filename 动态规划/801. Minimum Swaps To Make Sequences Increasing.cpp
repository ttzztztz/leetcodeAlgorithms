class Solution {
public:
    int N;
    int dfs(vector<vector<int>>& dp, vector<int>& A, vector<int>& B, int index, int last_changed) {
        if (index == N) {
            return 0;
        }
        if (dp[index][last_changed] != -1) {
            return dp[index][last_changed];
        }

        int answer = -1;
        int lastAi = A[index - 1], lastBi = B[index - 1];
        if (last_changed) {
            swap(lastAi, lastBi);
        }

        const bool b1 = (A[index] > lastAi) && (B[index] > lastBi), b2 = (B[index] > lastAi) && (A[index] > lastBi);

        if (!b1 && !b2) {
            answer = 9999999;
        } else if (b1 == b2) {
            answer = min(dfs(dp, A, B, index + 1, 0), dfs(dp, A, B, index + 1, 1) + 1);
        } else if (b1 && !b2) {
            answer = dfs(dp, A, B, index + 1, 0);
        } else if (!b1 && b2) {
            answer = 1 + dfs(dp, A, B, index + 1, 1);
        }

        return dp[index][last_changed] = answer;
    }

    int minSwap(vector<int>& A, vector<int>& B) {
        N = A.size();
        vector<vector<int>> dp(N + 5, vector<int>(2, -1));

        return min(dfs(dp, A, B, 1, 0), 1 + dfs(dp, A, B, 1, 1));
    }
};