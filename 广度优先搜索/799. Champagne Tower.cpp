class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n = query_row, m = query_glass;
        double f[105][105];
        memset(f, 0, sizeof f);

        typedef pair<int, int> PII;
        f[0][0] = poured;
        
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= x; y++) {
                if (f[x][y] >= 1.0) {
                    const double delta = f[x][y] - 1.0;
                    
                    f[x + 1][y] += delta / 2.0;
                    f[x + 1][y + 1] += delta / 2.0;
                    
                    f[x][y] = 1.0;
                }
            }
        }
        
        return min(f[n][m], 1.0);
    }
};
