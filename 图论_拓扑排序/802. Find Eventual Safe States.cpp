class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int N = graph.size();

        vector<vector<int>> newGraph(N, vector<int>{});
        vector<int> inDegree(N, 0);
        for (int u = 0; u < N; u++) {
            for (int v : graph[u]) {
                newGraph[v].push_back(u);
                inDegree[u]++;
            }
        }

        vector<int> answer;
        deque<int> queue;
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0) {
                answer.push_back(i);
                queue.push_back(i);
            }
        }

        while (!queue.empty()) {
            int u = queue.front();
            queue.pop_front();

            for (int v : newGraph[u]) {
                if (--inDegree[v] == 0) {
                    answer.push_back(v);
                    queue.push_back(v);
                }
            }
        }

        sort(answer.begin(), answer.end());
        return answer;
    }
};