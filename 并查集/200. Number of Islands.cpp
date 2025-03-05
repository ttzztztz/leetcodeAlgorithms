class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        n = grid.size(), m = grid[0].size();
        init();
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] != '1') continue;
            
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (valid_point(nx, ny) && grid[nx][ny] == '1') {
                    merge(id(nx, ny), id(i, j));
                }
            }
        }

        unordered_set<int> ans;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] != '1') continue;
            ans.insert(find_parent(id(i, j)));
        }
        return ans.size();
    }
private:
    int n, m;
    vector<int> parent;

    bool valid_point(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int id(int x, int y) {
        return x * m + y;
    }

    void init() {
        for (int i = 0; i < n * m; i++) {
            parent.push_back(i);
        }
    }

    int find_parent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }

    void merge(int x, int y) {
        const int parent_x = find_parent(x), parent_y = find_parent(y);
        if (parent_x != parent_y) {
            parent[parent_x] = parent_y;
        }
    }
};