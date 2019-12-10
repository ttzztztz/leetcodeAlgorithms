class Solution {
public:
    //  \0/
    //  1X2
    //  /3\

    int N, M;
    int ID(int x, int y, int direction) {
        return x * M * 4 + y * 4 + direction;
    }

    int parent[20000];
    void init() {
        for (int i = 0; i <= N * 4 * M * 4; i++) {
            parent[i] = i;
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
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        N = grid.size(), M = grid[0].size();
        init();

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == ' ') {
                    merge(ID(i, j, 0), ID(i, j, 1));
                    merge(ID(i, j, 0), ID(i, j, 2));
                    merge(ID(i, j, 0), ID(i, j, 3));
                } else if (grid[i][j] == '\\') {
                    merge(ID(i, j, 1), ID(i, j, 3));
                    merge(ID(i, j, 0), ID(i, j, 2));
                } else if (grid[i][j] == '/') {
                    merge(ID(i, j, 0), ID(i, j, 1));
                    merge(ID(i, j, 2), ID(i, j, 3));
                }

                if (i - 1 >= 0) {
                    merge(ID(i, j, 0), ID(i - 1, j, 3));
                }

                if (j - 1 >= 0) {
                    merge(ID(i, j, 1), ID(i, j - 1, 2));
                }
            }
        }

        unordered_set<int> already;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k <= 3; k++) {
                    const int p = findParent(ID(i, j, k));
                    if (!already.count(p)) {
                        answer++;
                        already.insert(p);
                    }
                }
            }
        }

        return answer;
    }
};