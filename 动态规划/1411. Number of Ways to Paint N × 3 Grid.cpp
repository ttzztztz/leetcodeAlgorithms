class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1e9+7;
        typedef long long ll;
        vector<vector<vector<ll>>> f(3, vector<vector<ll>>(3, vector<ll>(3, 0)));
        for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) for (int c = 0; c < 3; c++) {
            if (a == b || b == c) continue;
            f[a][b][c] = 1;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            vector<vector<vector<ll>>> g(3, vector<vector<ll>>(3, vector<ll>(3, 0)));
            
            for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) for (int c = 0; c < 3; c++) {
                if (a == b || b == c) continue;
                for (int x = 0; x < 3; x++) for (int y = 0; y < 3; y++) for (int z = 0; z < 3; z++) {
                    if (x == y || y == z || x == a || y == b || z == c) continue;
                    g[a][b][c] = (g[a][b][c] + f[x][y][z]) % mod;
                }
            }
            
            f = g;
        }
        
        ll ans = 0;
        for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) for (int c = 0; c < 3; c++) {
            if (a == b || b == c) continue;
            ans = (ans + f[a][b][c]) % mod;
        }
        return ans;
    }
};