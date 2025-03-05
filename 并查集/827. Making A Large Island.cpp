class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        n = grid.size(), m = grid[0].size();
        init(n * m);

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) continue;
            
            for (int k = 0; k < 4; k++) {
                const int ni = i + dx[k], nj = j + dy[k];
                if (!point_valid(ni, nj) || grid[ni][nj] == 0) continue;
                merge(id(i, j), id(ni, nj));
            }
            ans = max(ans, size[find_parent(id(i, j))]);
        }

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) continue;

            unordered_set<int> parents;
            for (int k = 0; k < 4; k++) {
                const int ni = i + dx[k], nj = j + dy[k];
                if (!point_valid(ni, nj) || grid[ni][nj] == 0) continue;
                parents.insert(find_parent(id(ni, nj)));
            }
            int cur_size = 1;
            for (int p : parents) cur_size += size[find_parent(p)];
            ans = max(ans, cur_size);
        }
        return ans;
    }
private:
    int n, m;
    vector<int> parent, size;

    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int id(int i, int j) {
        return i * m + j;
    }
    
    void init(int cnt) {
        parent = vector<int>(cnt + 1, 0);
        size = vector<int>(cnt + 1, 0);

        for (int i = 0; i <= cnt; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }

    void merge(int u, int v) {
        const int parent_u = find_parent(u);
        const int parent_v = find_parent(v);

        if (parent_u != parent_v) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
    }
};