class Solution {
public:
    int answer, n, m;
    int find_ans(vector<vector<int>>& grid, int i, int j) {
        int answer = 0;
        for (int k = 0; k < n; k++) {
            if (k == i) {
                continue;
            }

            if (grid[k][j] == 1) {
                return 1;
            }
        }
        for (int k = 0; k < m; k++) {
            if (k == j) {
                continue;
            }

            if (grid[i][k] == 1) {
                return 1;
            }
        }

        return 0;
    }
    int countServers(vector<vector<int>>& grid) {
        answer = 0, n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    answer += find_ans(grid, i, j);
                }
            }
        }

        return answer;
    }
};