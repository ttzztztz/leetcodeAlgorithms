class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        typedef long long ll;
        typedef pair<ll, ll> PII;
        const int mod = 1e9+7;
        
        vector<vector<PII>> edges(n);
        for (auto& road : roads) {
            const int u = road[0], v = road[1], w = road[2];
            edges[u].emplace_back(v, w);
            edges[v].emplace_back(u, w);
        }
        vector<ll> dist(n, numeric_limits<ll>::max() / 2), times(n, 0);
        times[0] = 1, dist[0] = 0;
        
        priority_queue<PII, vector<PII>, greater<>> heap;
        heap.emplace(0, 0);
        while (!heap.empty()) {
            auto[d, u] = heap.top();
            heap.pop();
            if (d != dist[u]) continue;
            
            for (auto& [v, w] : edges[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    times[v] = times[u];
                    heap.emplace(dist[v], v);
                } else if (d + w == dist[v]) {
                    times[v] = (times[v] + times[u]) % mod;
                }
            }
        }
        return times[n - 1];
    }
};