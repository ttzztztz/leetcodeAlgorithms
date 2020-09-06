class Solution {
public:
    vector<int> answer;
    vector<vector<int>> graph;
    vector<int> dist;
    int maxDistance, maxU;
    vector<bool> visited;

    void dfs1(int u, int d) {
        visited[u] = true;
        dist[u] = d;
        if (d > maxDistance) {
            maxDistance = d, maxU = u;
        }

        for (int v : graph[u]) {
            if (!visited[v]) {
                dfs1(v, d + 1);
            }
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.size() == 0) {
            return vector<int>{0};
        }

        graph = vector<vector<int>>(n, vector<int>());
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        visited = vector<bool>(n, false);
        dist = vector<int>(n, 0);
        maxDistance = 0, maxU = 0;
        dfs1(0, 1);

        visited = vector<bool>(n, false);
        dist = vector<int>(n, 0);
        const int u1 = maxU;
        maxDistance = 0, maxU = 0;
        dfs1(u1, 1);
        const int u2 = maxU;

        vector<int> route;
        int u = u2;
        while (dist[u1] != dist[u]) {
            route.push_back(u);
            for (int v : graph[u]) {
                if (dist[v] + 1 == dist[u]) {
                    u = v;
                    break;
                }
            }
        }
        route.push_back(u1);

        if (maxDistance % 2) {
            answer.push_back(route[maxDistance / 2]);
        } else {
            answer.push_back(route[maxDistance / 2]);
            answer.push_back(route[maxDistance / 2 - 1]);
        }
        return answer;
    }
};