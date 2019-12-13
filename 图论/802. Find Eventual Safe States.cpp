class Solution {
public:
    int N;

    // return true if discovered a cycle
    bool dfs(const vector<vector<int>>& graph, vector<int>& color, int u) {
        if (color[u] != 0) {
            return color[u] == 1;
        }

        color[u] = 1;
        for (int v : graph[u]) {
            if (color[v] == 2) {
                continue;
            }

            if (color[v] == 1 || dfs(graph, color, v)) {
                return true;
            }

        }
        color[u] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> answer;

        N = graph.size();
        vector<int> color(N, 0);

        // 0 -> white, 1 -> gray, 2 -> black
        for (int i = 0; i < N; i++) {
            if (color[i] == 2 || (color[i] == 0 && !dfs(graph, color, i))) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};