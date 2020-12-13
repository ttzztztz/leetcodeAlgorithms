class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        this->s = stones;
        memset(f, 0xff, sizeof f);
        memset(g, 0, sizeof g);
        n = stones.size();
        
        for (int i = 1; i <= s.size(); i++) g[i] = g[i - 1] + s[i - 1];
        return dfs(1, n, 0);
    }
private:
    int f[1005][1005][2], g[1005], n;
    vector<int> s;
    
    int dfs(int i, int j, int turn) {
        if (i > j) return 0;
        int& val = f[i][j][turn];
        if (val != -1) return val;
        
        int ans;
        if (turn == 0) { // Alice
            ans = max(
                dfs(i + 1, j, turn ^ 1) + g[j] - g[i],
                dfs(i, j - 1, turn ^ 1) + g[j - 1] - g[i - 1]
            );
        } else { // Bob
            ans = min(
                dfs(i + 1, j, turn ^ 1) - (g[j] - g[i]),
                dfs(i, j - 1, turn ^ 1) - (g[j - 1] - g[i - 1])
            );
        }
        
        return val = ans;
    }
};
