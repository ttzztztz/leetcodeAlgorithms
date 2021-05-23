class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        const int n = stones.size(), maxn = 100005;
        int psum[maxn], f[maxn][2], g[maxn], h[maxn];
        memset(psum, 0, sizeof psum);
        memset(f[0], 0xbf, sizeof f[0]);
        memset(f[1], 0x3f, sizeof f[1]);
        memset(g, 0xbf, sizeof g);
        memset(h, 0x3f, sizeof h);
        
        psum[0] = stones[0];
        for (int i = 1; i < n; i++) psum[i] = psum[i - 1] + stones[i];
        psum[n] = psum[n + 1] = psum[n - 1];
        
        f[n][0] = f[n][1] = 0;
        g[n] = psum[n];
        h[n] = -psum[n];
        for (int i = n - 1; i >= 1; i--) {
            f[i][0] = g[i + 1];
            f[i][1] = h[i + 1];
                
            g[i] = max(f[i][1] + (i >= 1 ? psum[i - 1] : 0), g[i + 1]);
            h[i] = min(f[i][0] - (i >= 1 ? psum[i - 1] : 0), h[i + 1]);
        }
        
        for (int i = 2; i <= n; i++) {
            f[0][0] = max(f[0][0], f[i][1]+ psum[i - 1]);
        }
        
        return f[0][0];
    }
};