class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> graph;
    vector<int> dfn, low;
    int current = 0;

    void dfs(int u, int parent) {
        dfn[u] = low[u] = ++current;

        for (int v : graph[u]) {
            if (v == parent) continue;

            if (dfn[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > dfn[u]) {
                    answer.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn = vector<int>(n, -1), low = vector<int>(n, -1);
        graph = vector<vector<int>>(n, vector<int>{});
        for (const vector<int>& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        dfs(0, -1);
        return answer;
    }
};