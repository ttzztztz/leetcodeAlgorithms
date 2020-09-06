class Solution {
public:
    int parent[2600], size[2600];
    int N, M;

    int ID(int i, int j) {
        return i * M + j;
    }
    void init() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                parent[ID(i, j)] = ID(i, j);
                size[ID(i, j)] = 1;
            }
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }
    void merge(int u, int v) {
        int parentU = findParent(u), parentV = findParent(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        init();
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        bool haveZero = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0) {
                    haveZero = true;
                    continue;
                }

                for (int k = 0; k < 4; k++) {
                    const int nextX = i + dx[k], nextY = j + dy[k];
                    if (pointValid(nextX, nextY) && grid[nextX][nextY] == 1) {
                        merge(ID(i, j), ID(nextX, nextY));
                    }
                }
            }
        }

        unordered_set<int> visited;
        multiset<int> componentSize;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] != 1) continue;

                const int parent = findParent(ID(i, j));
                if (!visited.count(parent)) {
                    visited.insert(parent);
                    componentSize.insert(size[parent]);
                }
            }
        }

        if (!haveZero) {
            return *componentSize.rbegin();
        }

        if (componentSize.size() == 0) {
            return 1;
        } else if (componentSize.size() == 1) {
            return *componentSize.rbegin() + 1;
        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int temp = 0;
                if (grid[i][j] == 1) continue;
                unordered_set<int> visited;

                for (int k = 0; k < 4; k++) {
                    const int nextX = i + dx[k], nextY = j + dy[k];
                    if (pointValid(nextX, nextY) && grid[nextX][nextY] == 1) {
                        const int parent = findParent(ID(nextX, nextY));
                        if (!visited.count(parent)) {
                            visited.insert(parent);
                            temp += size[parent];
                        }
                    }
                }

                answer = max(answer, temp + 1);
            }
        }
        return answer;
    }
};