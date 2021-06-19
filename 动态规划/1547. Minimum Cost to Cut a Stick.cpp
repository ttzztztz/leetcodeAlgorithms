class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        const int m = cuts.size();
        
        int f[105][105];
        memset(f, 0x3f, sizeof f);
        for (int len = 1; len <= m; len++) for (int i = 0; i + len - 1 < m; i++) {
            const int j = i + len - 1;
            
            const int l = (i - 1 >= 0) ? cuts[i - 1] : 0;
            const int r = (j + 1 < m) ? cuts[j + 1] : n;
            const int cost = r - l;
            
            for (int k = i; k <= j; k++) {
                f[i][j] = min(f[i][j], 
                              (k - 1 >= i ? f[i][k - 1] : 0) + 
                              (k + 1 <= j ? f[k + 1][j] : 0) + cost);
            }
        }
        return f[0][m - 1];
    }
};