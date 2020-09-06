class Solution {
public:
    int N;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < N;
    }
    bool isBorder(const vector<vector<int>>& A, int x, int y) {
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        
        for (int k = 0; k < 4; k++) {
            const int nx = x + dx[k], ny = y + dy[k];
            if (pointValid(nx, ny) && A[nx][ny] == 0) return true;
        }
        
        return false;
    }
    int parent[10005];
    void init() {
        for (int i = 0; i <= 10000; i++) {
            parent[i] = i;
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
        }
    }
    int ID(int x, int y) {
        return x * N + y;
    }
    int shortestBridge(vector<vector<int>>& A) {
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        N = A.size();
        init();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] != 1) continue;
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    
                    if (pointValid(nx, ny) && A[nx][ny] == 1) {
                        merge(ID(i, j), ID(nx, ny));
                    }
                }
            }
        }
        
        map<int, int> islandMap;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] != 1) continue;
                islandMap[findParent(ID(i, j))] = ID(i, j);
            }
        }
        
        vector<int> IDs;
        vector<int> parents;
        for (auto p : islandMap) {
            IDs.push_back(p.second);
            parents.push_back(p.first);
        }
        
        set<pair<int, int>> visited;
        deque<pair<int, int>> queue;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] != 1 || findParent(ID(i, j)) != parents[0]) continue;
                if (isBorder(A, i, j)) {
                    queue.emplace_back(i, j);
                    visited.emplace(i, j);
                }
            }
        }
        
        int answer = 0;
        while (!queue.empty()) {
            int size = queue.size();
            while (size--) {
                int x, y;
                tie(x, y) = queue.front();
                queue.pop_front();
                
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    
                    if (pointValid(nx, ny) && !visited.count({nx, ny})) {
                        if (A[nx][ny] == 1 && findParent(ID(nx, ny)) == parents[1]) {
                            return answer;
                        }
                        
                        visited.emplace(nx, ny);
                        queue.emplace_back(nx, ny);
                        merge(ID(x, y), ID(nx, ny));
                    }
                }
            }
            answer++;
        }
        return answer;
    }
};
