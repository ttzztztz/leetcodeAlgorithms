class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        vector<int> ans;
        const int n = matrix.size(), m = matrix[0].size();
        int x_min = 0, x_max = n - 1;
        int y_min = 0, y_max = m - 1;
        while (ans.size() < n * m) {
            for (int i = y_min; i <= y_max; i++) ans.push_back(matrix[x_min][i]);
            x_min++;
            if (x_min > x_max) break;

            for (int i = x_min; i <= x_max; i++) ans.push_back(matrix[i][y_max]);
            y_max--;
            if (y_min > y_max) break;

            for (int i = y_max; i >= y_min; i--) ans.push_back(matrix[x_max][i]);
            x_max--;
            if (x_min > x_max) break;

            for (int i = x_max; i >= x_min; i--) ans.push_back(matrix[i][y_min]);
            y_min++;
            if (y_min > y_max) break;
        }
        return ans;
    }
};