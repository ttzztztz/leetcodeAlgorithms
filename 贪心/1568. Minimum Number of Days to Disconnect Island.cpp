class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int one_cnt = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            one_cnt += grid[i][j];
        }
        
        if (all_zero(grid) || not_disconnected(grid)) return 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                if (not_disconnected(grid)) return 1;
                grid[i][j] = 1;
            }
        }
        return min(2, one_cnt);
    }
private:
    int n, m;
    bool all_zero(const vector<vector<int>>& grid) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) return false;
        }
        return true;
    }
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    int id(int i, int j) {
        return i * m + j;
    }
    
    int parent[1001];
    
    void init() {
        for (int i = 0; i <= 900; i++) {
            parent[i] = i;
        }
    }
    
    int find_parent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
    
    bool not_disconnected(const vector<vector<int>>& grid) {
        init();
        const int dx[] = { 0, 0, -1, 1 };
        const int dy[] = { -1, 1, 0, 0 };
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) continue;
            
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (point_valid(nx, ny) && grid[nx][ny] == 1) merge(id(i, j), id(nx, ny));
            }
        }
        
        unordered_set<int> all;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) continue;
            all.insert(find_parent(id(i, j)));
        }
        return all.size() >= 2;
    }
};