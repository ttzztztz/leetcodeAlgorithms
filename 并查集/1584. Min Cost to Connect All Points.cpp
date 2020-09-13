class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        vector<TII> v;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                v.emplace_back(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
            }
        }
        
        sort(v.begin(), v.end(), [](const auto& $1, const auto& $2) -> bool {
            return get<2>($1) < get<2>($2);
        });
        
        int answer = 0;
        init(n);
        for (auto& t : v) {
            int i, j, d;
            tie(i, j, d) = t;
            
            const int pi = fp(i), pj = fp(j);
            if (pi != pj) {
                merge(pi, pj);
                answer += d;
            }
        }
        return answer;
    }
private:
    typedef tuple<int, int, int> TII;
    int parent[1005];
    void init(int n) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int fp(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = fp(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = fp(u), pv = fp(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
        }
    }
};
