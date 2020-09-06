class Solution {
public:
    vector<double> prob, finalAnswer;
    vector<vector<int>> edge;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        finalAnswer = prob = vector<double>(n + 5, 0.0);
        edge = vector<vector<int>>(n + 5, vector<int>{});
        for (const vector<int>& e : edges) {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        
        deque<int> q;
        q.push_back(1);
        prob[1] = 1.0;
        int answer = 0;
        vector<bool> visited(n + 5, false);
        while (!q.empty()) {
            if (answer > t) break;
            
            int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                int u = q.front();
                q.pop_front();
                visited[u] = true;
                
                double p = 0.0;
                int cnt = 0;
                for (int v : edge[u]) {
                    if (!visited[v]) {
                        p += 1.0;
                        cnt++;
                    }
                }
                
                if (cnt == 0) finalAnswer[u] = prob[u];
                for (int v : edge[u]) {
                    if (visited[v]) continue;
                    
                    prob[v] = prob[u] * 1.0 / p;
                    if (answer + 1 == t) finalAnswer[v] = prob[v];
                    visited[v] = true;
                    q.push_back(v);
                }
            }
            answer++;
        }
        
        return finalAnswer[target];
    }
};
