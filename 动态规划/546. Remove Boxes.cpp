class Solution {
public:
    vector<vector<vector<int>>> dp;
    int dfs(const vector<int>& boxes, int i, int j, int k) {
        if (i == j) {
            return (k + 1) * (k + 1);
        }
        if (i > j) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int answer = dfs(boxes, i, j - 1, 0) + (k + 1) * (k + 1);
        for (int p = i; p + 1 <= j; p++) {
            if (boxes[p] == boxes[j]) {
                answer = max(answer, dfs(boxes, i, p, k + 1) + dfs(boxes, p + 1, j - 1, 0));
            }
        }
        return dp[i][j][k] = answer;
    }
    int removeBoxes(vector<int>& boxes) {
        const int N = boxes.size();
        dp = vector<vector<vector<int>>>(N + 5, vector<vector<int>>(N + 5, vector<int>(N + 5, -1)));

        return dfs(boxes, 0, N - 1, 0);
    }
};