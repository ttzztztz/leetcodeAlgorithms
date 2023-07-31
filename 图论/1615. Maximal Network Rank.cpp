class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> directly_connected(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (const auto& road : roads) {
            const int u = road[0], v = road[1];

            degree[u]++;
            degree[v]++;
            directly_connected[u][v] = directly_connected[v][u] = true;
        }

        int ans = 0;
        for (int u = 0; u < n; u++) for (int v = u + 1; v < n; v++) {
            ans = max(ans, degree[u] + degree[v] - (directly_connected[u][v] == 1));
        }
        return ans;
    }
};