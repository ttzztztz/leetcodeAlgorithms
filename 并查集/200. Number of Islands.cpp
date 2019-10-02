class Solution {
public:
    int parent[1000002];
    int N, M, totalIslands = 0;
    void init() {
        for (int i = 0; i <= 1000001; i++) {
            parent[i] = i;
        }
    }
    int ID(int x, int y) {
        return x * M + y;
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return parent[u];
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }
    void merge(int u, int v) {
        int parentU = findParent(u), parentV = findParent(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
            totalIslands--;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (0 == grid.size()) {
            return 0;
        }

        init();
        N = grid.size(), M = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    totalIslands++;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';

                    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                        merge(ID(i, j), ID(i - 1, j));
                    }
                    if (i + 1 < N && grid[i + 1][j] == '1') {
                        merge(ID(i, j), ID(i + 1, j));
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                        merge(ID(i, j), ID(i, j - 1));
                    }
                    if (j + 1 < M && grid[i][j + 1] == '1') {
                        merge(ID(i, j), ID(i, j + 1));
                    }
                }
            }
        }

        return totalIslands;
    }
};