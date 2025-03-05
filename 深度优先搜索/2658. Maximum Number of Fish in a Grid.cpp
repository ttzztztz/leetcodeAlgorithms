class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        n = grid.size(), m = grid[0].size(), g = grid;
        ans = 0;

        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] || g[i][j] == 0) continue;

                int current_answer = 0;
                dfs(i, j, current_answer);
                ans = max(ans, current_answer);
            }
        }

        return ans;
    }
private:
    int n, m, ans;
    vector<vector<bool>> visited;
    vector<vector<int>> g;

    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(int i, int j, int& current_answer) {
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        current_answer += g[i][j];
        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
            const int next_i = i + dx[k], next_j = j + dy[k];
            if (!point_valid(next_i, next_j) || visited[next_i][next_j] || g[next_i][next_j] == 0) continue;

            dfs(next_i, next_j, current_answer);
        }
    }
};