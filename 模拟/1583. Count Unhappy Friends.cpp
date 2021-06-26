class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int p[501][501], f[501];
        
        const int m = pairs.size();
        memset(p, 0x3f, sizeof p);
        memset(f, 0xff, sizeof f);
        
        for (int i = 0; i < n; i++) for (int j = 0; j < n - 1; j++) {
            p[i][preferences[i][j]] = j;
        }
        
        for (int i = 0; i < m; i++) {
            f[pairs[i][0]] = pairs[i][1];
            f[pairs[i][1]] = pairs[i][0];
        }
        
        int ans = 0;
        for (int x = 0; x < n; x++) {
            const int y = f[x];
            if (y == -1) continue;
            
            for (int i = 0; i < m; i++) {
                int u = pairs[i][0], v = pairs[i][1];
                if (p[x][u] < p[x][y] && p[u][x] < p[u][v]) {
                    ans++;
                    break;
                }
                
                swap(u, v);

                if (p[x][u] < p[x][y] && p[u][x] < p[u][v]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};