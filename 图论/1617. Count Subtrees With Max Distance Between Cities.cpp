class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        this->n = n;
        const int INF = 99999;
        w = vector<vector<int>>(n, vector<int>(n, INF));
        ans = vector<int>(n - 1, 0);
        visited = vector<bool>((1 << n) + 5, false);
        
        for (auto& v : edges) w[v[0] - 1][v[1] - 1] = w[v[1] - 1][v[0] - 1] = 1;
        for (int i = 0; i < n; i++) w[i][i] = 0;
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
                }
            }
        }
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 cout << i << ", " << j << ", " << w[i][j] << endl;
//             }
//         }
        
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (w[u][v] != 1) continue;
                
                if (!visited[(1 << u) | (1 << v)]) {
                    visited[(1 << u) | (1 << v)] = true;
                    dfs((1 << u) | (1 << v));
                }
            }
        }
        return ans;
    }
private:
    vector<int> ans;
    vector<bool> visited;
    vector<vector<int>> w;
    int n;
    
    void dfs(int state) {
        int dist = 1;
        for (int u = 0; u < n; u++) {
            if (!(state & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (!(state & (1 << v))) continue;
                
                dist = max(dist, w[u][v]);
            }
        }
        ans[dist - 1]++;
        
        for (int u = 0; u < n; u++) {
            if (!(state & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (state & (1 << v)) continue;
                if (w[u][v] != 1) continue;
                
                if (!visited[state | (1 << v)]) {
                    visited[state | (1 << v)] = true;
                    dfs(state | 1 << v);
                }
            }
        }
        
    }
};
