class Solution {
public:
    /**
     * @param a: the node a
     * @param b: the node b
     * @return: nothing
     */
    void addEdge(int a, int b) {
        if (haveCircle) return;
        
        const int pa = fp(a), pb = fp(b);
        if (pa == pb) {
            haveCircle = true;
            return;
        }
        
        f.insert(a), f.insert(b);
        merge(a, b);
    }

    /**
     * @return: check whether these edges make up a valid tree
     */
    bool isValidTree() {
        if (haveCircle) return false;
        if (f.empty()) return true;
        
        const int u = *f.begin();
        const int pu = fp(u);
        return size[pu] == f.size();
    }
private:
    bool haveCircle = false, inited = false;
    unordered_set<int> f;
    int parent[100005], size[100005];
    void init() {
        for (int i = 0; i <= 100000; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int fp(int u) {
        if (!inited) init(), inited = true;
        
        if (parent[u] == u) return u;
        else return parent[u] = fp(parent[u]);
    }
    
    void merge(int u, int v) {
        if (!inited) init(), inited = true;
        
        const int pu = fp(u), pv = fp(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
