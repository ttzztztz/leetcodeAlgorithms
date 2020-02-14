class Solution {
public:
    /**
     * @param start: The start of the edges set
     * @param end: The end of the edges set
     * @return: Return the subtree count
     */
    int getSubtreeCount(vector<int> &start, vector<int> &end) {
        const int M = start.size();
        const int N = max(*max_element(start.begin(), start.end()), *max_element(end.begin(), end.end()));
        
        edge = vector<vector<int>>(N + 1, vector<int>{});
        dp = vector<vector<long long>>(N + 1, vector<long long>(2, 0));
        for (int i = 0; i < M; i++) {
            edge[start[i]].push_back(end[i]);
            edge[end[i]].push_back(start[i]);
        }
        
        dfs(1, -1);
        return (dp[1][0] + dp[1][1]) % MOD;;
    }
private:
    vector<vector<int>> edge;
    vector<vector<long long>> dp;
    int MOD = 1e7+7;
    void dfs(int u, int parent) {
        dp[u][0] = 0;
        dp[u][1] = 1;
        
        for (int v : edge[u]) {
            if (v == parent) continue;
            
            dfs(v, u);
            dp[u][0] += dp[v][0] + dp[v][1];
            dp[u][0] %= MOD;
            
            dp[u][1] *= (1 + dp[v][1]);
            dp[u][1] %= MOD;
        }
    }
};
