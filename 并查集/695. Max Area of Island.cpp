class Solution {
public:
    int N, M;

    int parent[2605], size[2605];
    int ID(int x, int y) {
        return x * M + y;
    }
    void init() {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                parent[ID(i, j)] = ID(i, j);
                size[ID(i, j)] = 1;
            }
        }
    }
    int findParent(int u) {
        if (parent[u] != u) {
            return parent[u] = findParent(parent[u]);
        } else {
            return u;
        }
    }
    void merge(int u, int v) {
        const int parentU = findParent(u), parentV = findParent(v);

        if (parentU != parentV) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();

        init();
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        int answer = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0) continue;

                for (int k = 0; k < 4; k++) {
                    const int nextX = i + dx[k], nextY = j + dy[k];

                    if (pointValid(nextX, nextY) && grid[nextX][nextY] == 1) {
                        merge(ID(i, j), ID(nextX, nextY));
                    }
                }

                answer = max(answer, size[findParent(ID(i, j))]);
            }
        }

        return answer;
    }
};