class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int answer = 0, type3answer = 0;
        typedef pair<int, int> PII;
        vector<PII> edg[5];
        for (auto& e : edges) {
            edg[e[0]].emplace_back(e[1], e[2]);
        }
        
        init();
        for (auto& p : edg[3]) {
            int u, v;
            tie(u, v) = p;
            
            if (findParent(u) != findParent(v)) {
                merge(u, v);
            } else {
                type3answer++;
            }
        }
        
        for (auto& p : edg[1]) {
            int u, v;
            tie(u, v) = p;
            
            if (findParent(u) != findParent(v)) {
                merge(u, v);
            } else {
                answer++;
            }
        }
        
        if (size[findParent(1)] != n) return -1;
        init();
        for (auto& p : edg[3]) {
            int u, v;
            tie(u, v) = p;
            
            if (findParent(u) != findParent(v)) {
                merge(u, v);
            }
        }
        
        for (auto& p : edg[2]) {
            int u, v;
            tie(u, v) = p;
            
            if (findParent(u) != findParent(v)) {
                merge(u, v);
            } else {
                answer++;
            }
        }
        
        if (size[findParent(1)] != n) return -1;
        return answer + type3answer;
    }
private:
    int parent[100005], size[100005];
    void init() {
        for (int i = 0; i <= 100000; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int u) {
        if (u == parent[u]) return u;
        else return parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = findParent(u), pv = findParent(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
