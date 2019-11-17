class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int N = grid.size(), M = grid[0].size();

        for (int K = 0; K < k; K++) {
            vector<vector<int>> newGrid(N, vector<int>(M, 0));

            for (int i = 0; i < N; i++) {
                if (i + 1 < N) {
                    newGrid[i + 1][0] = grid[i][M - 1];
                }

                for (int j = 0; j < M - 1; j++) {
                    newGrid[i][j + 1] = grid[i][j];
                }
            }
            newGrid[0][0] = grid[N - 1][M - 1];

            grid = newGrid;
        }

        return grid;
    }
};