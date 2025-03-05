class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        color = vector<int>(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !dfs(graph, i, 0)) return false;
        }
        return true;
    }
private:
    int n;
    vector<int> color;
    bool dfs(const vector<vector<int>>& edges, int u, int col) {
        color[u] = col;

        for (int v : edges[u]) {
            if (color[v] == col) return false;
            if (color[v] == (col ^ 1)) continue;
            if (!dfs(edges, v, col ^ 1)) return false;
        }
        return true;
    }
};