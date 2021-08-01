class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        n = grid.size(), m = grid[0].size();
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        init();
        int ans = 1;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) continue;
            
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (point_valid(nx, ny) && grid[nx][ny] == 1) {
                    merge(id(i, j), id(nx, ny));
                    ans = max(ans, max(
                        size[find_parent(id(i, j))],
                        size[find_parent(id(nx, ny))]
                    ));
                }
            }
        }
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) continue;
            
            unordered_set<int> components;
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (point_valid(nx, ny) && grid[nx][ny] == 1) {
                    components.insert(find_parent(id(nx, ny)));
                }
            }
            
            int cur = 1;
            for (int i : components) cur += size[i];
            ans = max(ans, cur);
        }
        return ans;
    }
private:
    int n, m;
    int parent[260001], size[260001];
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    int id(int i, int j) {
        return i * m + j;
    }
    
    void init() {
        for (int i = 0; i <= (n * m) + 1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find_parent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};