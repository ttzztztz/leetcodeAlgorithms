class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& e, int t, int target) {
        this->t = t;
        memset(f, 0, sizeof f);
        memset(outdegree, 0, sizeof outdegree);
        
        edges = vector<vector<int>>(n + 1);
        for (auto& ed : e) {
            edges[ed[0]].push_back(ed[1]);
            edges[ed[1]].push_back(ed[0]);
        }
        
        dfs(1, -1, 0);
        return f[target][t];
    }
private:
    double f[105][55];
    int t;
    int outdegree[105];
    vector<vector<int>> edges;
    
    void dfs(int u, int parent, int time) {
        if (parent == -1) f[u][time] = 1.0;
        else f[u][time] = f[parent][time - 1] / outdegree[parent];
        
        for (int v : edges[u]) {
            if (v == parent) continue;
            outdegree[u]++;
        }
        
        if (outdegree[u] == 0) {
            for (int x = time + 1; x <= t; x++) f[u][x] = f[u][time];
        } else {
            for (int v : edges[u]) {
                if (v == parent) continue;
                dfs(v, u, time + 1);
            }
        }
    }
};