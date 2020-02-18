class Solution {
public:
    /**
     * @param grid: a grid
     * @param hits: some erasures order
     * @return: an array representing the number of bricks that will drop after each erasure in sequence
     */
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        vector<vector<int>> originGrid = grid;
        N = grid.size(), M = grid[0].size();
        const int Q = hits.size();
        init();
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (vector<int>& hit : hits) grid[hit[0]][hit[1]] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0) continue;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (pointValid(nx, ny) && grid[nx][ny] == 1) {
                        merge(ID(i, j), ID(nx, ny));
                    }
                }
                
                if (i == 0) {
                    merge(ID(0, j), ID(N, M));
                }
            }
        }
        
        vector<int> answer(Q, 0);
        multiset<pair<int, int>> mset;
        for (vector<int>& hit : hits) mset.emplace(hit[0], hit[1]);
        for (int i = Q - 1; i >= 0; i--) {
            const int x = hits[i][0], y = hits[i][1];
            if (originGrid[x][y] != 1) continue;
        
            mset.erase(mset.find({x, y}));
            if (mset.count({x, y})) continue;
            
            const int prev = size[findParent(ID(N, M))];
            grid[x][y] = 1;
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (pointValid(nx, ny) && grid[nx][ny] == 1) {
                    merge(ID(x, y), ID(nx, ny));
                }
            }
            if (x == 0) {
                merge(ID(0, y), ID(N, M));
            }
            
            const int after = size[findParent(ID(N, M))];
            answer[i] = max(0, after - prev - 1);
        }
        return answer;
    }
private:
    int parent[42000], size[42000];
    int N, M;
    inline int ID(int x, int y) {
        return x * M + y;
    }
    void init() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                parent[ID(i, j)] = ID(i, j);
                size[ID(i, j)] = 1;
            }
        }
        
        parent[ID(N, M)] = ID(N, M);
        size[ID(N, M)] = 1;
    }
    int findParent(int i) {
        if (parent[i] == i) {
            return i;
        } else {
            return parent[i] = findParent(parent[i]);
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
};


