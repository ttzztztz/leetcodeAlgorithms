class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        const int inf = numeric_limits<int>::max() / 2;
        
        this->n = n;
        ans = vector<int>(n - 1, 0);
        visited = vector<bool>((1 << n) + 1, false);
        dist = vector<vector<int>>(n + 1, vector<int>(n + 1, inf));
        
        for (auto& e : edges) {
            int &u = e[0], &v = e[1];
            u--, v--;

            dist[u][v] = dist[v][u] = 1;
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        
        for (int k = 0; k < n; k++) {
            for (int u = 0; u < n; u++) for (int v = 0; v < n; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }

        for (auto& e : edges) {
            const int u = e[0], v = e[1];
            dfs((1 << u) | (1 << v));
        }
        return ans;
    }
private:
    vector<int> ans;
    vector<bool> visited;
    vector<vector<int>> dist;
    int n;
    
    void dfs(int state) {
        if (visited[state]) return;
        visited[state] = true;
        
        int d = 1;
        for (int u = 0; u < n; u++) {
            if (!(state & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (!(state & (1 << v))) continue;
                d = max(d, dist[u][v]);
            }
        }
        ans[d - 1]++;
        
        for (int u = 0; u < n; u++) {
            if (state & (1 << u)) for (int v = 0; v < n; v++) {
                if (!(state & (1 << v)) && dist[u][v] == 1) {
                    dfs(state | (1 << v));
                }
            }
        }
    }
};