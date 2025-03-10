class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;

        const int n = mat.size(), m = mat[0].size();
        vector<vector<int>> h(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (mat[i][j] == '0') continue;

            if (i - 1 >= 0) h[i][j] = h[i - 1][j] + 1;
            else h[i][j] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> l(m, 0), r(m, 0), stk;
            for (int j = 0; j < m; j++) {
                while (!stk.empty() && h[i][stk.back()] >= h[i][j]) stk.pop_back();

                if (stk.empty()) l[j] = -1;
                else l[j] = stk.back();

                stk.push_back(j);
            }

            stk.clear();
            for (int j = m - 1; j >= 0; j--) {
                while (!stk.empty() && h[i][stk.back()] >= h[i][j]) stk.pop_back();

                if (stk.empty()) r[j] = m;
                else r[j] = stk.back();

                stk.push_back(j);
            }

            for (int j = 0; j < m; j++) {
                const int len = min(h[i][j], (r[j] - l[j] - 1));
                ans = max(ans, len * len);
            }
        }
        return ans;
    }
};