class Solution {
public:
    int parent[250100], size[250100];
    int N, M;
    void init() {
        const int maxX = N + 2, maxY = M + 2;
        for (int i = 0; i <= maxX * maxY; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return parent[u];
        } else {
            return parent[u] = findParent(parent[u]);
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
    int ID(int x, int y) {
        return x * M + y;
    }
    int numEnclaves(vector<vector<int>>& A) {
        int total = 0;
        
        N = A.size(), M = A[0].size();
        init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] == 1) total++;
            }
        }
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int i = 0; i < N; i++) {
            const int x1 = i, y1 = 0;
            if (A[x1][y1] == 1) {
                for (int k = 0; k < 4; k++) {
                    const int nx = x1 + dx[k], ny = y1 + dy[k];
                    if (pointValid(nx, ny) && A[nx][ny] == 1) {
                        merge(ID(x1, y1), ID(nx, ny));
                    }
                }
            }
            
            const int x2 = i, y2 = M - 1;
            if (A[x2][y2] == 1) {
                for (int k = 0; k < 4; k++) {
                    const int nx = x2 + dx[k], ny = y2 + dy[k];
                    if (pointValid(nx, ny) && A[nx][ny] == 1) {
                        merge(ID(x2, y2), ID(nx, ny));
                    }
                }
            }
        }
        for (int i = 0; i < M; i++) {
            const int x1 = 0, y1 = i;
            if (A[x1][y1] == 1) {
                for (int k = 0; k < 4; k++) {
                    const int nx = x1 + dx[k], ny = y1 + dy[k];
                    if (pointValid(nx, ny) && A[nx][ny] == 1) {
                        merge(ID(x1, y1), ID(nx, ny));
                    }
                }
            }
            
            const int x2 = N - 1, y2 = i;
            if (A[x2][y2] == 1) {
                for (int k = 0; k < 4; k++) {
                    const int nx = x2 + dx[k], ny = y2 + dy[k];
                    if (pointValid(nx, ny) && A[nx][ny] == 1) {
                        merge(ID(x2, y2), ID(nx, ny));
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (pointValid(nx, ny) && A[nx][ny] == 1) {
                        merge(ID(i, j), ID(nx, ny));
                    }
                }
            }
            }
        }
        
        
        unordered_set<int> visited;
        int canReach = 0;
        for (int i = 0; i < N; i++) {
            const int x1 = i, y1 = 0;
            if (A[x1][y1] == 1) {
                const int p = findParent(ID(x1, y1));
                if (!visited.count(p)) {
                    visited.insert(p);
                    canReach += size[p];
                }
            }
            
            const int x2 = i, y2 = M - 1;
            if (A[x2][y2] == 1) {
                const int p = findParent(ID(x2, y2));
                if (!visited.count(p)) {
                    visited.insert(p);
                    canReach += size[p];
                }
            }
        }
        for (int i = 0; i < M; i++) {
            const int x1 = 0, y1 = i;
            if (A[x1][y1] == 1) {
                const int p = findParent(ID(x1, y1));
                if (!visited.count(p)) {
                    visited.insert(p);
                    canReach += size[p];
                }
            }
            
            const int x2 = N - 1, y2 = i;
            if (A[x2][y2] == 1) {
                const int p = findParent(ID(x2, y2));
                if (!visited.count(p)) {
                    visited.insert(p);
                    canReach += size[p];
                }
            }
        }
        
        return total - canReach;
    }
};
