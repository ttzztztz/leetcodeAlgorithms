class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        const int n = rs.size(), m = cs.size();
        data = vector<vector<int>>(n, vector<int>(m, 0));
        dfs(rs, cs, 0);
        return data;
    }
private:
    vector<vector<int>> data;
    void dfs(vector<int>& rs, vector<int>& cs, int a) {
        const int n = rs.size(), m = cs.size();

        if (n == 0 || m == 0) return;
        if (n == 1) {
            for (int j = 0; j < m; j++) data[a][a + j] = cs[j];
            return;
        } else if (m == 1) {
            for (int j = 0; j < n; j++) data[a + j][a] = rs[j];
            return;
        }
        
        data[a][a] = min(rs[0], cs[0]);
        if (rs[0] < cs[0]) {
            int rest = cs[0] - rs[0], ptr = 1;
            while (rest) {
                data[ptr + a][a] = min(rest, rs[ptr]);
                rest -= min(rest, rs[ptr]);
                rs[ptr] -= data[ptr + a][a];
                ptr++;
            }
        } else {
            int rest = rs[0] - cs[0], ptr = 1;
            while (rest) {
                data[a][a + ptr] = min(rest, cs[ptr]);
                rest -= min(rest, cs[ptr]);
                cs[ptr] -= data[a][a + ptr];
                ptr++;
            }
        }
        
        rs.erase(rs.begin());
        cs.erase(cs.begin());
        dfs(rs, cs, a + 1);
    }
};
