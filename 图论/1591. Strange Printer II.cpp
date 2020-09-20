class Solution {
public:
    bool isPrintable(vector<vector<int>>& g) {
        typedef pair<int, int> Point;
        const int n = g.size(), m = g[0].size();
        
        vector<Point> v[65];
        vector<vector<int>> edges(65);
        vector<int> ind(65);
        int solved = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                const int t = g[i][j];
                v[t].emplace_back(i, j);
            }
        }
        
        for (int i = 1; i <= 60; i++) {
            int min_x = 99999, min_y = 99999, max_x = -1, max_y = -1;
            auto& all = v[i];
            if (all.empty()) continue;
            
            for (auto& p : all) {
                int x, y;
                tie(x, y) = p;
                min_x = min(min_x, x);
                max_x = max(max_x, x);
                
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
            
            for (int a = min_x; a <= max_x; a++) {
                for (int b = min_y; b <= max_y; b++) {
                    if (g[a][b] != i) {
                        edges[g[a][b]].push_back(i);
                        ind[i]++;
                    }
                }
            }
        }
        
        deque<int> q;
        for (int i = 1; i <= 60; i++) {
            if (ind[i] == 0) q.push_back(i);
        }
        
        while (!q.empty()) {
            const int u = q.front();
            solved++;
            q.pop_front();
            
            for (int v : edges[u]) {
                ind[v]--;
                if (ind[v] == 0) q.push_back(v);
            }
        }
        
        return solved == 60;
    }
};
