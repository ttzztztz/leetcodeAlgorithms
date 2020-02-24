class Solution {
public:
    /**
     * @param graph: the graph
     * @return: the shortest path for all nodes
     */
    int shortestPathLength(vector<vector<int>> &graph) {
        const int N = graph.size();
        if (N == 0 || graph[0].empty()) return 0;
        
        vector<vector<int>> dist(N, vector<int>(N, 9999999));
        for (int u = 0; u < N; u++) {
            for (int v : graph[u]) dist[u][v] = dist[v][u] = 1;
        }
        
        for (int k = 0; k < N; k++) {
            for (int u = 0; u < N; u++) {
                for (int v = 0; v < N; v++) {
                    if (u != v && dist[u][v] > dist[u][k] + dist[k][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                    }
                }
            }
        }
        
        vector<vector<int>> dp(1 << N, vector<int>(N, 9999999));
        const int mask = (1 << N) - 1;
        for (int i = 0; i < N; i++) dp[0][i] = 0;
        
        for (int i = 1; i <= mask; i++) {
            for (int j = 0; j < N; j++) {
                if (!(i & (1 << j))) continue;
                for (int k = 0; k < N; k++) {
                    dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + dist[k][j]);
                }
            }
        }
        
        int answer = 9999999;
        for (int i = 0; i < N; i++) answer = min(answer, dp[mask][i]);
        return answer - 1;
    }
};
