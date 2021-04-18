class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        const int n = points.size(), m = queries.size();
        vector<int> ans(m, 0);
        
        for (int i = 0; i < m; i++) {
            const int x = queries[i][0], y = queries[i][1], r = queries[i][2];
            for (int j = 0; j < n; j++) {
                const int px = points[j][0], py = points[j][1];
                if ((px - x) * (px - x) + (py - y) * (py - y) <= r * r) ans[i]++;
            }
        }
        return ans;
    }
};