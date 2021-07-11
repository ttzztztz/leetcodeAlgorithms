int dist[1001][1001];
vector<pair<int, int>> edge[1001];

class State {
public:
    int cost, time, u;
    State(int c, int t, int _u) {
        cost = c, time = t, u = _u;
    };
};

struct cmp {
    bool operator() (const State& $1, const State& $2) const {
        return $1.cost > $2.cost;
    }
};

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        const int n = passingFees.size(), inf = numeric_limits<int>::max() / 2;
        
        memset(dist, 0x3f, sizeof dist);
        for (int i = 0; i < n; i++) edge[i].clear();
        
        dist[0][0] = passingFees[0];
        for (auto& e : edges) {
            edge[e[0]].emplace_back(e[1], e[2]);
            edge[e[1]].emplace_back(e[0], e[2]);
        }
        
        priority_queue<State, vector<State>, cmp> heap;
        heap.emplace(passingFees[0], 0, 0);
        
        while (!heap.empty()) {
            auto[c, t, u] = heap.top();
            heap.pop();
            
            if (t > maxTime) continue;
            if (u == n - 1) return c;
            
            for (auto&[v, delta_t] : edge[u]) {
                const int nt = t + delta_t;
                if (nt > maxTime) continue;
                
                if (dist[u][t] + passingFees[v] < dist[v][nt]) {
                    dist[v][nt] = dist[u][t] + passingFees[v];
                    heap.emplace(dist[u][t] + passingFees[v], t + delta_t, v);
                }
            }
        }
        return -1;
    }
};