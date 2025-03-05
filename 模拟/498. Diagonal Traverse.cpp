class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};

        vector<int> ans;
        const int n = mat.size(), m = mat[0].size();
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        for (int i = 0; i < n + m - 1; i++) {
            int x = 0, y = 0, dx = 0, dy = 0;
            if (i % 2 == 0) {
                dx = -1, dy = 1;
                x = i < n ? i : n - 1;
                y = i < n ? 0 : i - n + 1;
            } else { // i % 2 == 1
                dx = 1, dy = -1;
                x = i < m ? 0 : i - m + 1;
                y = i < m ? i : m - 1;
            }

            while (point_valid(x, y)) {
                ans.push_back(mat[x][y]);
                x += dx, y += dy;
            }
        }
        return ans;
    }
};