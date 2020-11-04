class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        edges = vector<vector<int>>(n + 1, vector<int>{});
        for (auto& ed : e) {
            edges[ed[0]].push_back(ed[1]);
            edges[ed[1]].push_back(ed[0]);
        }
        
        vector<int> ans;
        dfs1(0, -1, 0);
        
        dist = -1;
        dfs2(far, -1, 0);
        
        const int p = path.size();
        if (p % 2 == 0) {
            ans = { path[p / 2], path[p / 2 - 1] };
        } else {
            ans = { path[p / 2] };
        }
        return ans;
    }
private:
    vector<vector<int>> edges;
    vector<int> path, cur;
    int far = -1, dist = -1;
    void dfs1(int u, int parent, int d) {
        if (d > dist) far = u, dist = d;
        
        for (int v : edges[u]) {
            if (v == parent) continue;
            dfs1(v, u, d + 1);
        }
    }
    
    void dfs2(int u, int parent, int d) {
        cur.push_back(u);
        if (d > dist) path = cur, dist = d;
        
        for (int v : edges[u]) {
            if (parent == v) continue;
            dfs2(v, u, d + 1);
        }
        cur.pop_back();
    }
};
