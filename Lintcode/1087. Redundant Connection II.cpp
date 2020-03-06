class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        init();
        
        vector<int> firstAppear, secondAppear;
        vector<int> father(1005, -1);
        
        for (vector<int>& e : edges) {
            const int u = e[0], v = e[1];
            if (father[v] != -1) {
                firstAppear = {father[v], v};
                secondAppear = {u, v};
                
                e[0] = e[1] = -1;
            }
            father[v] = u;
        }
        
        for (const vector<int>& e : edges) {
            if (e[0] == -1 && e[1] == -1) continue;
            
            const int pU = findParent(e[0]), pV = findParent(e[1]);
            if (pU == pV) {
                if (firstAppear.empty()) {
                    return {e[0], e[1]};
                } else {
                    return firstAppear;
                }
            } else {
                merge(e[0], e[1]);
            }
        }
        
        return secondAppear;
    }
private:
    vector<int> parent;
    void init() {
        parent = vector<int>(1005, 0);
        for (int i = 0; i <= 1000; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return parent[u];
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (pU != pV) {
            parent[pU] = pV;
        }
    }
};
