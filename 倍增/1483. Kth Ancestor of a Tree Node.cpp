class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        memset(f, 0xff, sizeof f);
        for (int i = 0; i < n; i++) {
            f[i][0] = parent[i];
        }
        
        for (int i = 1; i <= 30; i++) {
            for (int u = 0; u < n; u++) {
                const int t = f[u][i - 1];
                if (t != -1) f[u][i] = f[t][i - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int u = node;
        for (int i = 30; i >= 0; i--) {
            if (k & (1 << i)) {
                if (u == -1) return -1;
                u = f[u][i];
            }
        }
        return u;
    }
private:
    int f[50005][31];
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */