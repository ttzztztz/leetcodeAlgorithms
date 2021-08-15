class Solution {
public:
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        auto id = [&](int i, int j) -> int {
            return i * m + j;
        };
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        vector<vector<int>> state(n, vector<int>(m, 0));
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        init();
        
        for (int days = cells.size() - 1; days >= 0; days--) {
            const int x = cells[days][0] - 1, y = cells[days][1] - 1;

            state[x][y] = 1;
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (point_valid(nx, ny) && state[nx][ny] == 1) merge(id(x, y), id(nx, ny));
            }
            
            if (x == 0) merge(id(x, y), upper);
            if (x == n - 1) merge(id(x, y), lower);
            
            if (find_parent(upper) == find_parent(lower)) return days;
        }
        return -1; // never reach this branch
    }
private:
    int parent[20005];
    
    const int upper = 20001, lower = 20002;
    void init() {
        for (int i = 0; i <= 20002; i++) {
            parent[i] = i;
        }
    }
    
    int find_parent(int u) {
        if (u == parent[u]) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        parent[pu] = pv;
    }
};