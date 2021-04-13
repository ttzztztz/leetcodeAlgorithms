int f[500001][4];

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        memset(f, 0xff, sizeof f);
        obs = obstacles;
        n = obs.size() - 1;
        
        return dfs(0, 2);
    }
private:
    vector<int> obs;
    int n;
    int dfs(int u, int l) {
        if (u == n) return 0;
        int& val = f[u][l];
        if (val != -1) return val;
        int ans = 9999999;
        for (int k = 1; k <= 3; k++) {
            if (obs[u] == k || obs[u + 1] == k) continue;
            ans = min(ans, (k != l) + dfs(u + 1, k));
        }
        return val = ans;
    }
};
