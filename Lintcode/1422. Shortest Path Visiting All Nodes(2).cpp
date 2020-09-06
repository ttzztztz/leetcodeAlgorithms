class Solution {
public:
    /**
     * @param graph: the graph
     * @return: the shortest path for all nodes
     */
    typedef pair<int, int> Point;
    int shortestPathLength(vector<vector<int>> &g) {
        const int N = g.size();
        if (N == 0 || g[0].empty()) return 0;
        
        vector<vector<int>> graph(N, vector<int>{});
        for (int u = 0; u < N; u++) {
            for (int v : g[u]) {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        
        int answer = 0;
        const int mask = (1 << N) - 1;
        vector<vector<bool>> visited(1 << N, vector<bool>(N, false));
        
        deque<Point> q;
        for (int i = 0; i < N; i++) {
            q.emplace_back(1 << i, i);
            visited[1 << i][i] = true;
        }
        
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                int state, u;
                tie(state, u) = q.front();
                q.pop_front();
                
                if (state == mask) return answer;
                for (int v : graph[u]) {
                    const int ns = state | (1 << v);
                    if (visited[ns][v]) continue;
                    if (ns == mask) return answer + 1;
                    visited[ns][v] = true;
                    q.emplace_back(ns, v);
                }
            }
            answer++;
        }
        
        return 0;
    }
};
