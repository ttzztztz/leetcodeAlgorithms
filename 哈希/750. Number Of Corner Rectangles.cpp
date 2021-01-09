class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        n = grid.size(), m = grid[0].size();
        
        vector<pair<int, int>> point;
        unordered_set<int> point_set;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    point.emplace_back(i, j);
                    point_set.insert(hash(i, j));
                }
            }
        }
        
        int ans = 0;
        const int t = point.size();
        for (int i = 0; i < t; i++) {
            for (int j = i + 1; j < t; j++) {
                auto [x1, y1] = point[i];
                auto [x2, y2] = point[j];
                
                if (x1 == x2 || y1 == y2) continue;
                if (point_set.count(hash(x1, y2)) && point_set.count(hash(x2, y1))) {
                    ans++;
                }
            }
        }
        return ans / 2;
    }
private:
    int n, m;
    int hash(int i, int j) {
        return i * m + j;
    }
};
