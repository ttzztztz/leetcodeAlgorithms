class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> edge(n), edge_rev(n);
        for (auto& e : edges) {
            edge[e[0]].emplace_back(e[1], e[2]);
            edge_rev[e[1]].emplace_back(e[0], e[2]);
        }
        
        vector<ll> d_src1 = dijk(edge, n, src1);
        vector<ll> d_src2 = dijk(edge, n, src2);
        vector<ll> d_dest = dijk(edge_rev, n, dest);
        
        ll ans = inf;
        for (int i = 0; i < n; i++) {
            if (d_src1[i] >= inf || d_src2[i] >= inf || d_dest[i] >= inf) continue;
            ans = min(ans, d_src1[i] + d_src2[i] + d_dest[i]);
        }
        
        if (ans < inf) return ans;
        else return -1;
    }
private:
    typedef long long ll;
    const ll inf = numeric_limits<ll>::max() / 2;
    
    vector<ll> dijk(const vector<vector<pair<int, int>>>& edges, const int n, int u) {
        typedef pair<ll, int> State; // [w, u]
        priority_queue<State, vector<State>, greater<>> heap;
        vector<ll> dist(n, inf);
        
        heap.emplace(0, u);
        dist[u] = 0;
        
        while (!heap.empty()) {
            auto[w, u] = heap.top();
            heap.pop();
            if (w != dist[u]) continue;
            
            for (auto& [v, nw] : edges[u]) {
                if (dist[v] > dist[u] + nw) {
                    dist[v] = dist[u] + nw;
                    heap.emplace(dist[u] + nw, v);
                }
            }
        }
        return dist;
    }
};
