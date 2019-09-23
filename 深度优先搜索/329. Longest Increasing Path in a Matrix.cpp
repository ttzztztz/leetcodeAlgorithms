int dp[1005][1005];

class Solution {
public:
    inline bool pointValid(int x, int y, int maxX, int maxY) {
        return !(x < 0 || y < 0 || x >= maxX || y >= maxY);
    }

    int dfs(int x, int y, int maxX, int maxY, const vector<vector<int>> &matrix) {
        if (dp[x][y] != 1) {
            return dp[x][y];
        }

        int newPath = 0;
        if (pointValid(x - 1, y, maxX, maxY) && matrix[x - 1][y] > matrix[x][y]) {
            newPath = std::max(newPath, dfs(x - 1, y, maxX, maxY, matrix) + 1);
        }
        if (pointValid(x + 1, y, maxX, maxY) && matrix[x + 1][y] > matrix[x][y]) {
            newPath = std::max(newPath, dfs(x + 1, y, maxX, maxY, matrix) + 1);
        }
        if (pointValid(x, y - 1, maxX, maxY) && matrix[x][y - 1] > matrix[x][y]) {
            newPath = std::max(newPath, dfs(x, y - 1, maxX, maxY, matrix) + 1);
        }
        if (pointValid(x, y + 1, maxX, maxY) && matrix[x][y + 1] > matrix[x][y]) {
            newPath = std::max(newPath, dfs(x, y + 1, maxX, maxY, matrix) + 1);
        }

        return dp[x][y] = newPath;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                dp[i][j] = 1;
            }
        }

        int answer = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                answer = std::max(answer, dfs(i, j, matrix.size(), matrix[i].size(), matrix) + 1);
            }
            cout << endl;
        }
        return answer;
    }
};