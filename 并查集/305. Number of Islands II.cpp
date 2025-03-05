class Solution {
public:
    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        auto id = [&](int i, int j) -> int {
            return i * m + j;
        };
        const int dx[] = { 0, 0, -1, 1 };
        const int dy[] = { -1, 1, 0, 0 };

        init(n * m);
        vector<vector<int>> grid(n, vector<int>(m, 0));
        int cur = 0;
        vector<int> ans;
        for (auto& position : positions) {
            const int x = position[0], y = position[1];
            if (grid[x][y] == 1) {
                ans.push_back(cur);
                continue;
            }

            grid[x][y] = 1;
            unordered_set<int> components;
            const int cur_id = id(x, y);

            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (point_valid(nx, ny) && grid[nx][ny] == 1) {
                    components.insert(find_parent(id(nx, ny)));
                }
            }
            
            for (int component : components) {
                merge(component, cur_id);
            }

            // len = 0 -> ans + 1
            // len = 1 -> ans
            // len = 2 -> ans - 1
            // len = 3 -> ans - 2
            // len = 4 -> ans - 3
            cur += 1 - components.size();
            ans.push_back(cur);
        }
        return ans;
    }
private:
    vector<int> parent;

    void init(int total) {
        parent = vector<int>(total + 1, 0);
        for (int i = 0; i <= total; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }

    void merge(int u, int v) {
        const int parent_u = find_parent(u), parent_v = find_parent(v);
        if (parent_u != parent_v) {
            parent[parent_u] = parent_v;
        }
    }
};