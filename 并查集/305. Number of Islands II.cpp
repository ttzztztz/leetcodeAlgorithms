class Solution {
public:
    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        const int k = positions.size();
        init(n * m);
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> ans;
        int cur = 0;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        for (auto& position : positions) {
            const int x = position[0], y = position[1];
            
            if (grid[x][y] == 0) {
                unordered_set<int> adjacent_component;
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (!point_valid(nx, ny) || grid[nx][ny] == 0) continue;
                    adjacent_component.insert(find_parent(nx * m + ny));
                }

                const int adjacent_component_size = adjacent_component.size();
                cur -= adjacent_component_size - 1;
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (!point_valid(nx, ny) || grid[nx][ny] == 0) continue;
                    merge(x * m + y, nx * m + ny);
                }

                grid[x][y] = 1;
            }
            
            ans.push_back(cur);
        }
        return ans;
    }
private:
    vector<int> parent_;
    void init(int n) {
        parent_ = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent_[i] = i;
        }
    }
    int find_parent(int u) {
        if (parent_[u] == u) return u;
        else return parent_[u] = find_parent(parent_[u]);
    }
    void merge(int u, int v) {
        const int parent_u = find_parent(u), parent_v = find_parent(v);
        if (parent_u != parent_v) {
            parent_[parent_u] = parent_v;
        }
    }
};
