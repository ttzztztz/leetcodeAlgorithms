class Solution {
public:
    /**
     * @param matrix: the matrix for calculation.
     * @return: return the max area after operation at most once.
     */
    int maxArea(vector<vector<int>> &matrix) {
        N = matrix.size(), M = matrix[0].size();
        init();
        int answer = calc(matrix);
        
        const int cur = answer;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] != 0) continue;
                
                int add = 0;
                unordered_set<int> allp;
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (pointValid(nx, ny) && matrix[nx][ny] == 1) {
                        const int p = findParent(ID(nx, ny));
                        if (!allp.count(p)) {
                            add += size[p];
                            allp.insert(p);
                        }
                        
                    }
                }
                answer = max(answer, max(cur, 1 + add));
            }
        }
        
        return max(1, answer);
    }
private:
    int N, M;
    int parent[250005];
    int size[250005];
    
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    void init() {
        for (int i = 0; i <= 250000; i++) parent[i] = i, size[i] = 1;
    }
    int ID(int x, int y) {
        return x * M + y;
    }
    int findParent(int u) {
        if (u == parent[u]) return u;
        else return parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = findParent(u), pv = findParent(v);
        
        if (parent[pu] != pv) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    int calc(const vector<vector<int>>& matrix) {
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] != 1) continue;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (pointValid(nx, ny) && matrix[nx][ny] == 1) {
                        merge(ID(i, j), ID(nx, ny));
                    }
                }
                
            }
        }
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] != 1) continue;
                
                answer = max(answer, size[findParent(ID(i, j))]);
            }
        }
        return answer;
    }
};
