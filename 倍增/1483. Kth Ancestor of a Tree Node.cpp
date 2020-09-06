class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        memset(f, 0xff, sizeof f);
        for (int i = 0; i < parent.size(); i++) {
            f[i][0] = parent[i];
        }
        
        for (int j = 1; j <= 17; j++) {
            for (int i = 0; i <= n; i++) {
                const int t = f[i][j - 1];
                if (t != -1) f[i][j] = f[t][j - 1];
                else f[i][j] = -1;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cur = 0;
        for (int i = 17; i >= 0; i--) {
            if ((cur | (1 << i)) <= k) {
                cur |= 1 << i;
                node = f[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }
private:
    int f[50004][18];
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
