class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        this->favorite = favorite;
        const int n = favorite.size();
        if (n <= 2) return n;
        
        edges = vector<vector<int>>(n, vector<int>{});
        for (int i = 0; i < n; i++) edges[favorite[i]].push_back(i);
        
        // case 1: max cycle
        visited = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            dfs(i, 0);
        }
        
        // case 2: AAAA B<=>C DDDD
        visited = vector<bool>(n, false);
        for (int i = 0; i < n; i++) if (favorite[favorite[i]] == i) {
            if (visited[i] || visited[favorite[i]]) continue;
            visited[i] = visited[favorite[i]] = true;
            
            int l = 0, r = 0;
            for (int x : edges[i]) {
                if (x == favorite[i]) continue;
                l = max(l, preceding(x));
            }
            
            for (int x : edges[favorite[i]]) {
                if (x == i) continue;
                r = max(r, preceding(x));
            }
            ans_case2 += l + r + 2;
        }
        
        return max(ans_case1, ans_case2);
    }
private:
    vector<int> favorite;
    vector<vector<int>> edges;
    vector<bool> visited;
    unordered_map<int, int> stk_idx, memo;
    int ans_case1 = 0, ans_case2 = 0;
    
    void dfs(int u, int idx) {
        if (stk_idx.count(u)) {
            const int cycle_size = idx - stk_idx[u];
            ans_case1 = max(ans_case1, cycle_size);
            return;
        }
        if (visited[u]) {
            return;
        }

        visited[u] = true;
        stk_idx[u] = idx;
        dfs(favorite[u], idx + 1);
        stk_idx.erase(u);
    }
    
    int preceding(int u) {
        if (memo.count(u)) return memo[u];
        int ans = 1;
        for (int v : edges[u]) {
            ans = max(ans, 1 + preceding(v));
        }
        return memo[u] = ans;
    }
};
