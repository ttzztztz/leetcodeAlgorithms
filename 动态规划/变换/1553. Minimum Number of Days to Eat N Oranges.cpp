class Solution {
public:
    int minDays(int n) {
        return dfs(n);
    }
private:
    unordered_map<int, int> f;
    int dfs(int u) {
        if (u == 0) return 0;
        if (u == 1) return 1;
        if (f.count(u)) return f[u];
        int ans = min(u, 1 + min((u % 2) + dfs(u / 2), (u % 3) + dfs(u / 3)));
        return f[u] = ans;
    }
};