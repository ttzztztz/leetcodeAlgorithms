class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        const int RED = 0, BLUE = 1;
        vector<int> answer(n, -1);

        answer[0] = 0;
        vector<vector<vector<int>>> graph(n, vector<vector<int>>(2, vector<int>{}));
        for (const vector<int>& edge : red_edges) {
            graph[edge[0]][0].push_back(edge[1]);
        }
        for (const vector<int>& edge : blue_edges) {
            graph[edge[0]][1].push_back(edge[1]);
        }

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        deque<tuple<int, int, int>> queue;
        queue.emplace_back(0, RED, 0);
        queue.emplace_back(0, BLUE, 0);
        while (!queue.empty()) {
            int u, color, dist;
            tie(u, color, dist) = queue.front();
            queue.pop_front();

            if (answer[u] == -1 || answer[u] > dist) {
                answer[u] = dist;
            }
            for (int v : graph[u][!color]) {
                if (!visited[v][!color]) {
                    visited[v][!color] = true;
                    queue.emplace_back(v, !color, dist + 1);
                }
            }
        }
        return answer;
    }
};