class Solution {
public:
    bool isOk;
    vector<int> color;
    void dfs(const vector<vector<int>>& graph, int u, int c) {
        if (!isOk) {
            return;
        }

        color[u] = c;
        for (int v : graph[u]) {
            if (color[v] == c) {
                isOk = false;
                return;
            }

            if (color[v] == -1) {
                dfs(graph, v, !c);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        isOk = true;
        const int N = graph.size();
        color = vector<int>(N, -1);

        for (int u = 0; u < N; u++) {
            if (color[u] == -1) {
                dfs(graph, u, 1);
            }
        }

        return isOk;
    }
};