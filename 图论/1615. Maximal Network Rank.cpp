class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> edges(n, vector<int>(n, 0));
        for (auto& v : roads) {
            edges[v[0]][v[1]] = edges[v[1]][v[0]] = 1;
        }
        
        bool visited[105][105];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int ext = 0;
                if (edges[i][j]) ext = 1;
                memset(visited, 0, sizeof visited);
                visited[i][j] = true;
                
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    if (!visited[i][k] && edges[i][k]) {
                        visited[i][k] = true;
                        ext++;
                    }
                    if (!visited[k][j] && edges[k][j]) {
                        visited[k][j] = true;
                        ext++;
                    }
                }
                
                ans = max(ans, ext);
            }
        }
        return ans;
    }
};
