class Solution {
public:
    /**
     * @param matrix: a two-dimensional matrix.
     * @param pixelThreshold: the pixel threshold judging high click position.
     * @param areaThreshold: the pixed threshold judging high click area.
     * @return: return the number of high click areas.
     */
    int highClickAreaCount(vector<vector<int>> &matrix, int pixelThreshold, int areaThreshold) {
        N = matrix.size(), M = matrix[0].size();
        init();
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        auto satisfy = [&](int i, int j) -> bool {
            return matrix[i][j] > pixelThreshold;
        };
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!satisfy(i, j)) continue;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (pointValid(nx, ny) && satisfy(nx, ny)) {
                        merge(id(i, j), id(nx, ny));
                    }
                }
            }
        }
        
        int answer = 0;
        unordered_set<int> already;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!satisfy(i, j)) continue;
                
                const int p = findParent(id(i, j));
                if (already.count(p)) continue;
                if (sze[p] <= areaThreshold) continue;
                already.insert(p);
                answer++;
            }
        }
        return answer;
    }
private:
    int N, M;
    vector<int> parent, sze;
    void init() {
        parent = vector<int>((N + 1) * (M + 1));
        sze = vector<int>((N + 1) * (M + 1));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                parent[id(i, j)] = id(i, j);
                sze[id(i, j)] = 1;
            }
        }
    }
    int id(int i, int j) {
        return i * M + j;
    }
    int findParent(int u) {
        if (parent[u] == u) return u;
        else parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (pU != pV) {
            parent[pU] = pV;
            sze[pV] += sze[pU];
        }
    }
};
