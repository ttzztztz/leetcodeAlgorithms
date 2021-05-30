typedef long long ll;
ll up[101][101][101], down[101][101][101];

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<ll> all;
        const int n = grid.size(), m = grid[0].size();
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        auto push_heap = [&](ll val) -> void {
            all.insert(val);
        };
        memset(up, 0, sizeof up);
        memset(down, 0, sizeof down);
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            up[i][j][0] = grid[i][j];
            int l = j - 1, r = j + 1, t = 1;
            while (point_valid(i + t, l) && point_valid(i + t, r)) {
                up[i][j][t] = up[i][j][t - 1] + grid[i + t][l] + grid[i + t][r];
                l--, r++, t++;
            }
        }
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            down[i][j][0] = grid[i][j];
            int l = j - 1, r = j + 1, t = 1;
            while (point_valid(i - t, l) && point_valid(i - t, r)) {
                down[i][j][t] = down[i][j][t - 1] + grid[i - t][l] + grid[i - t][r];
                l--, r++, t++;
            }
        }
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            push_heap(grid[i][j]);
            
            for (int r = 1; r <= max(n, m); r++) {
                const int lx = i - r, rx = i + r;
                const int ly = j - r, ry = j + r;
                
                if (
                    !point_valid(lx, j) 
                    || !point_valid(rx, j) 
                    || !point_valid(i, ly) 
                    || !point_valid(i, ry)
                ) continue;
                
                const ll val = up[lx][j][r] + down[rx][j][r] - grid[i][ly] - grid[i][ry];
                push_heap(val);
            }
        }
        
        vector<int> ans;
        for (auto i = all.rbegin(); i != all.rend() && ans.size() < 3; i++) {
            ans.push_back(*i);
        }
        return ans;
    }
};