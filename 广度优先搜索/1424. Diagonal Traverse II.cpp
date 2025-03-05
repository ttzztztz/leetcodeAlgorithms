class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};

        deque<pair<int, int>> q = { {0, 0} };
        vector<int> ans;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();

            ans.push_back(mat[x][y]);
            if (y == 0 && x + 1 < mat.size()) q.emplace_back(x + 1, y);
            if (y + 1 < mat[x].size()) q.emplace_back(x, y + 1);
        }
        return ans;
    }
};