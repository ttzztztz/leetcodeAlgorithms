class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        init(n);
        const int m = edges.size();
        if (n - 1 != m) return false;
        
        for (const auto& edge : edges) {
            const int pu = find_parent(edge[0]);
            const int pv = find_parent(edge[1]);
            
            if (pu == pv) return false;
            merge(edge[0], edge[1]);
        }
        
        for (int i = 1; i < n; i++) {
            if (find_parent(0) != find_parent(i)) return false;
        }
        return true;
    }
private:
    vector<int> parent;
    void init(int n) {
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find_parent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
};
