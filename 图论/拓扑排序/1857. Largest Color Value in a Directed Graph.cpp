class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int n = colors.size();
        
        vector<vector<int>> edge(n, vector<int>{});
        vector<vector<int>> f(n, vector<int>(26, 0));
        vector<int> ind(n, 0);
        
        for (auto& e : edges) {
            ind[e[1]]++;
            edge[e[0]].push_back(e[1]);
        }
        
        deque<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) q.push_back(i);
        }
        
        int finished = 0, ans = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop_front();
            finished++;
            
            f[u][colors[u] - 'a']++;
            ans = max(ans, f[u][colors[u] - 'a']);
            for (int v : edge[u]) {
                ind[v]--;
                if (ind[v] == 0) {
                    q.push_back(v);
                }
                
                for (int j = 0; j < 26; j++) {
                    f[v][j] = max(f[v][j], f[u][j]);
                    ans = max(ans, f[v][j]);
                }
            }
        }
        
        if (finished == n) return ans;
        else return -1;
    }
};
