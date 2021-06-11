class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        typedef pair<double, int> State;
        vector<vector<State>> edge(n);
        
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            edge[e[0]].emplace_back(succProb[i], e[1]);
            edge[e[1]].emplace_back(succProb[i], e[0]);
        }
        
        priority_queue<State, vector<State>, less<>> heap;
        heap.emplace(1.0, start);
        vector<double> dist(n, 0.0);
        while (!heap.empty()) {
            auto [val, u] = heap.top();
            if (u == end) return val;
            dist[u] = val;
            heap.pop();
            
            for (auto& [w, v] : edge[u]) {
                if (val * w > dist[v]) {
                    dist[v] = val * w;
                    heap.emplace(val * w, v);
                }
            }
        }
        return 0.0;
    }
};