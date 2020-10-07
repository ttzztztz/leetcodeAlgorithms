class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        const int n = rs.size(), m = cs.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0, j = 0; i < n && j < m;) {
            const int a = min(rs[i], cs[j]);
            ans[i][j] = a;
            
            rs[i] -= a, cs[j] -= a;
            if (rs[i] == 0) i++;
            if (cs[j] == 0) j++;
        }
        return ans;
    }
};
