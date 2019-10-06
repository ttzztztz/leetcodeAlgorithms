class Solution {
public:
    int parent[400505], size[400505], R, C, top;
    vector<vector<int>> currentGrid;
    int ID(int r, int c) {
        return r * C + c;
    }
    void init() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                parent[ID(i, j)] = ID(i, j);
                size[ID(i, j)] = 1;
            }
        }

        parent[top] = top;
        size[top] = 1;
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
        if (parentU == parentV) {
            return;
        }
        parent[parentU] = parentV;
        size[parentV] += size[parentU];
    }
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < R && y < C;
    }
    void mergeAdjacentGrid(int i, int j) {
        if (i == 0 && currentGrid[i][j] == 1) {
            merge(top, ID(i, j));
        }
        if (pointValid(i - 1, j) && currentGrid[i - 1][j] == 1) {
            merge(ID(i, j), ID(i - 1, j));
        }
        if (pointValid(i + 1, j) && currentGrid[i + 1][j] == 1) {
            merge(ID(i, j), ID(i + 1, j));
        }
        if (pointValid(i, j - 1) && currentGrid[i][j - 1] == 1) {
            merge(ID(i, j), ID(i, j - 1));
        }
        if (pointValid(i, j + 1) && currentGrid[i][j + 1] == 1) {
            merge(ID(i, j), ID(i, j + 1));
        }
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        this->R = grid.size();
        this->C = grid[0].size();
        top = ID(R, C + 1);
        init();

        currentGrid = grid;
        vector<int> answer(hits.size(), 0);
        for (const vector<int>& hit : hits) {
            int r = hit[0], c = hit[1];
            currentGrid[r][c] = 0;
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (currentGrid[i][j] != 1) {
                    continue;
                }
                mergeAdjacentGrid(i, j);
            }
        }

        for (int i = hits.size() - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] != 1) {
                continue;
            }

            currentGrid[r][c] = 1;
            int previousSize = size[findParent(top)];
            mergeAdjacentGrid(r, c);
            int afterSize = size[findParent(top)];
            answer[i] = std::max(0, afterSize - previousSize - 1);
        }

        return answer;
    }
};