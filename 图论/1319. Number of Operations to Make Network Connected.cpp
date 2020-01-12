class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> edge;
    void dfs(int u, int parent) {
        visited[u] = true;
        for (int v : edge[u]) {
            if (v == parent) continue;
            if (!visited[v]) {
                dfs(v, u);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        const int minRequired = n - 1;
        if (minRequired > connections.size()) return -1;
        visited = vector<bool>(n + 5, false);
        edge = vector<vector<int>>(n + 5, vector<int>{});
        for (const vector<int>& connection : connections) {
            edge[connection[0]].push_back(connection[1]);
            edge[connection[1]].push_back(connection[0]);
        }
        
        int connectedComponent = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                connectedComponent++;
                dfs(i, -1);
            }
        }
        
        return connectedComponent - 1;
    }
};
