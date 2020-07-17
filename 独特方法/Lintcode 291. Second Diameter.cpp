class Solution {
public:
    /**
     * @param edge: edge[i][0] [1] [2]  start point,end point,value
     * @return: return the second diameter length of the tree
     */
    long long getSecondDiameter(vector<vector<int>> &edge) {
        for (const auto& e : edge) {
            N = max(N, e[0]);
            N = max(N, e[1]);
        }
        edges = vector<vector<PII>>(N + 1, vector<PII>{});
        
        for (const auto& e : edge) {
            edges[e[0]].emplace_back(e[1], e[2]);
            edges[e[1]].emplace_back(e[0], e[2]);
        }
        
        vector<long long> dist1 = calc(0);
        int p1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();
        vector<long long> dist2 = calc(p1);
        int p2 = max_element(dist2.begin(), dist2.end()) - dist2.begin();
        vector<long long> dist3 = calc(p2);
        int p3 = max_element(dist3.begin(), dist3.end()) - dist3.begin();
        
        long long answer = 0;
        for (int i = 0; i <= N; i++) {
            if (i != p2) answer = max(answer, dist2[i]);
            if (i != p3) answer = max(answer, dist3[i]);
        }
        return answer;
    }
private:
    int N = 0;
    typedef pair<int, int> PII;
    vector<vector<PII>> edges;
    vector<long long> calc(int u) {
        vector<long long> answer(N + 1, 0);
        vector<bool> visited(N + 1, false);
        
        visited[u] = true;
        deque<int> q = {u};
        while (!q.empty()) {
            const int k = q.front();
            q.pop_front();
            visited[k] = true;
            
            for (auto& ve: edges[k]) {
                int v, w;
                tie(v, w) = ve;
                
                if (!visited[v]) {
                    q.push_back(v);
                    visited[v] = true;
                    answer[v] = w + answer[k];
                }
            }
        }
        
        return answer;
    }
};
