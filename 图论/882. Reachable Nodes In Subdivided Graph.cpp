class Edge {
public:
    int u, v, w, used[2];
    Edge() : u(0), v(0), w(0) {
        used[0] = used[1] = 0;
    };
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {
        used[0] = used[1] = 0;
    };
    int sum() const {
        const int answer = used[0] + used[1];
        if (answer >= w) {
            return w;
        } else {
            return answer;
        }
    }
};

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<Edge> edge;
        int edgePtr = 0;
        vector<vector<pair<int, int>>> g(N, vector<pair<int, int>>{});
        for (const vector<int>& e : edges) {
            edge.emplace_back(e[0], e[1], e[2]);
            g[e[0]].push_back({edgePtr, 0});
            g[e[1]].push_back({edgePtr, 1});
            edgePtr++;
        }
        
        vector<bool> visited(N, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> queue;
        queue.emplace(M, 0);
        int answer = 0;
        
        while (!queue.empty()) {
            int dist, u;
            tie(dist, u) = queue.top();
            queue.pop();
            if (visited[u]) continue;
            visited[u] = true;
            answer++;
            
            for (int i = 0; i < g[u].size(); i++) {
                int edgeId, order;
                tie(edgeId, order) = g[u][i];
                Edge& e = edge[edgeId];
                const int v = order == 0 ? e.v : e.u;
                
                e.used[order] = max(e.used[order], dist);
                if (dist >= e.w + 1) {
                    queue.emplace(dist - e.w - 1, v);
                }
            }
        }
        
        for (const Edge& e : edge) {
            answer += e.sum();
        }
        return answer;
    }
};
