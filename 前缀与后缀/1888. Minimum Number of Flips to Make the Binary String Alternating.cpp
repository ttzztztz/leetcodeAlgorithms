class Solution {
public:
    int minFlips(string s) {
        this->s = s, n = s.size();
        int ans = n;
        
        memset(f, 0xff, sizeof f);
        memset(g, 0xff, sizeof g);
        
        for (int i = -1; i <= n; i++) {
            const int len1 = i + 1, len2 = n - i - 1;
            
            const int a = dfs1(i, len1 % 2 ? 1 : 0) + dfs2(i + 1, len2 % 2 ? 0 : 1);
            const int b = dfs1(i, len1 % 2 ? 0 : 1) + dfs2(i + 1, len2 % 2 ? 1 : 0);
            
            // cout << i << "," << dfs1(i, len1 % 2 ? 1 : 0) << "," << dfs2(i + 1, len2 % 2 ? 0 : 1) << endl;
            // cout << dfs1(i, len1 % 2 ? 0 : 1) << "," << dfs2(i + 1, len2 % 2 ? 1 : 0) << endl;
            ans = min(ans, min(a, b));
        }
        return ans;
    }
private:
    int n;
    int f[100005][2], g[100005][2];
    string s;
    
    int dfs1(int idx, int cur) {
        if (idx <= -1) return 0;
        
        int& val = f[idx][cur];
        if (val != -1) return val;
        
        int ans = dfs1(idx - 1, cur ^ 1) + (s[idx] - '0' != cur);
        return val = ans;
    }
    
    int dfs2(int idx, int cur) {
        if (idx >= n) return 0;
        
        int& val = g[idx][cur];
        if (val != -1) return val;
        
        int ans = dfs2(idx + 1, cur ^ 1) + (s[idx] - '0' != cur);
        return val = ans;
    }
};