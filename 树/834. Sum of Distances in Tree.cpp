class Solution {
public:
    vector<int> answer;
    vector<int> size;
    vector<vector<int>> graph;
    int N;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        this->N = N;

        answer = vector<int>(N, 0);
        size = vector<int>(N, 0);
        graph.resize(N, vector<int>{});

        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return answer;
    }
    void dfs1(int u, int parent) {
        for (int v : graph[u]) {
            if (v == parent) continue;

            dfs1(v, u);
            size[u] += size[v];
            answer[u] += answer[v] + size[v];
        }

        size[u]++;
    }
    void dfs2(int u, int parent) {
        for (int v : graph[u]) {
            if (v == parent) continue;

            answer[v] = answer[u] - 2 * size[v] + N;
            dfs2(v, u);
        }
    }
};