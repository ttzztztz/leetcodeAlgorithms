class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int m, int target) {
        if (houses.empty()) return (target == 0) ? 0 : -1;
        
        vector<vector<int>> f(m, vector<int>(target + 1, inf));
        for (int i = n; i >= 1; i--) {
            vector<vector<int>> g(m, vector<int>(target + 1, inf));
            for (int j = 0; j < m; j++) for (int k = 0; k <= target; k++) {
                int& val = g[j][k];
                if (i == n) {
                    val = (k == 0) ? 0 : inf;
                    continue;
                }

                if (houses[i] != 0) { // have color
                    if (j == houses[i] - 1) val = f[houses[i] - 1][k];
                    else if (k >= 1) val = f[houses[i] - 1][k - 1];
                } else {
                    for (int c = 0; c < m; c++) {
                        const int cos = cost[i][c];

                        if (j == c) val = min(val, cos + f[c][k]);
                        else if (k >= 1) val = min(val, cos + f[c][k - 1]);
                    }
                }
            }
            f = g;
        }

        int ans = inf;
        if (houses[0] != 0) {
            ans = f[houses[0] - 1][target - 1];
        } else {
            for (int i = 0; i < m; i++) ans = min(ans, cost[0][i] + f[i][target - 1]);
        }

        if (ans >= inf) return -1;
        return ans;
    }
private:
    const int inf = numeric_limits<int>::max() / 3;
};