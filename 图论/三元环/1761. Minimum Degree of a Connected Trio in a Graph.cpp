class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> deg(n + 1, 0);
        for (auto& edge : edges) {
            const int u = edge[0], v = edge[1];
            deg[u]++, deg[v]++;
        }
        
        vector<unordered_set<int>> direct_edges(n + 1);
        for (auto& edge : edges) {
            const int u = edge[0], v = edge[1];
            if (deg[u] < deg[v]) direct_edges[v].insert(u);
            else direct_edges[u].insert(v);
        }
        
        int ans = numeric_limits<int>::max();
        for (int u = 1; u <= n; u++) {
            for (int v : direct_edges[u]) {
                for (int w : direct_edges[v]) {
                    
                    if (direct_edges[u].count(w) || direct_edges[w].count(u)) {
                        ans = min(ans, deg[u] + deg[v] + deg[w] - 6);
                    }
                    
                }
            }
        }
        
        if (ans == numeric_limits<int>::max()) return -1;
        else return ans;
    }
};

// class Solution {
// public:
//     int minTrioDegree(int n, vector<vector<int>>& edges) {
//         vector<int> deg(n + 1, 0);
//         vector<unordered_set<int>> edges_set(n + 1);
//         for (auto& edge : edges) {
//             const int u = edge[0], v = edge[1];
//             deg[u]++, deg[v]++;
            
//             edges_set[v].insert(u);
//             edges_set[u].insert(v);
//         }
        
//         vector<vector<int>> direct_edges(n + 1);
//         for (auto& edge : edges) {
//             const int u = edge[0], v = edge[1];
//             if (deg[u] < deg[v]) direct_edges[v].push_back(u);
//             else direct_edges[u].push_back(v);
//         }
        
//         int ans = numeric_limits<int>::max();
//         for (int u = 1; u <= n; u++) {
//             for (int v : direct_edges[u]) {
//                 for (int w : direct_edges[v]) {
                    
//                     if (edges_set[u].count(w)) {
//                         ans = min(ans, deg[u] + deg[v] + deg[w] - 6);
//                     }
                    
//                 }
//             }
//         }
        
//         if (ans == numeric_limits<int>::max()) return -1;
//         else return ans;
//     }
// };