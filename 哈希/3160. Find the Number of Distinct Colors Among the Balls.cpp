class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        const int q = queries.size();
        unordered_map<int, int> balls, color;

        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++) {
            const auto& query = queries[i];
            const int x = query[0];
            const int y = query[1];

            if (balls.count(x)) {
                const int prev_color = balls[x];
                color[prev_color]--;
                if (color[prev_color] == 0) {
                    color.erase(color.find(prev_color));
                }
            }

            balls[x] = y;
            color[y]++;
            ans[i] = color.size();
        }
        return ans;
    }
};