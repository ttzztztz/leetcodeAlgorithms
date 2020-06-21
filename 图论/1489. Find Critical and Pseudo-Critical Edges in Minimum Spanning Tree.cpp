class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n + 5, 0);
        this->n = n;
        vector<int> critical, pseudo;
        
        const int M = edges.size();
        for (int i = 0; i < M; i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[2] < $2[2];
        });
        const int mst = MST(edges, -1, -1);
        
        for (int i = 0; i < M; i++) {
            if (MST(edges, -1, i) > mst) critical.push_back(i);
            else if (MST(edges, i, -1) == mst) pseudo.push_back(i);
        }
        
        return {critical, pseudo};
    }
private:
    int n;
    void init() {
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int findParent(int u) {
        if (u == parent[u]) return u;
        else return parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (parent[pU] != pV) parent[pU] = pV;
    }
    int MST(const vector<vector<int>>& edges, int forceInsert, int forceDelete) {
        init();
        int answer = 0;
        if (forceInsert != -1) {
            for (const auto& e : edges) {
                if (e[3] == forceInsert) {
                    answer += e[2];
                    merge(e[0], e[1]);
                    break;
                }
            }
        }
        
        for (const auto& e : edges) {
            if (forceDelete == e[3]) continue;
            if (findParent(e[0]) == findParent(e[1])) continue;
            
            answer += e[2];
            merge(e[0], e[1]);
        }
        
        for (int i = 1; i < n; i++) {
            if (findParent(0) != findParent(i)) return 9999999;
        }
        return answer;
    }
    vector<int> parent;
};
