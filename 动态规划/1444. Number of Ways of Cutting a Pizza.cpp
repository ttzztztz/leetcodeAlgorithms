class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        memset(f, 0xff, sizeof f);
        
        return dfs(pizza, 0, 0, k);
    }
private:
    const int MOD = 1e9+7;
    long long f[51][51][15];
    long long dfs(const vector<string>& p, int i, int j, int k) {
        if (i >= p.size() || j >= p[i].size()) return 0;
        if (f[i][j][k] != -1) return f[i][j][k];
        if (k == 1) {
            bool haveApple = false;
            for (int a = i; a < p.size(); a++) {
                for (int b = j; b < p[a].size(); b++) {
                    if (p[a][b] == 'A') {
                        haveApple = true;
                        break;
                    }
                }
                if (haveApple) break;
            }
            return f[i][j][k] = (haveApple ? 1 : 0);
        }
        
        long long answer = 0;
        
        bool haveApple = false;
        for (int a = i; a < p.size(); a++) {
            if (!haveApple) {
                for (int b = j; b < p[a].size(); b++) {
                    if (p[a][b] == 'A') {
                        haveApple = true;
                        break;
                    }
                }
            }
            
            if (haveApple) {
                answer += dfs(p, a + 1, j, k - 1);
                answer %= MOD;
            }
        }
        
        haveApple = false;
        for (int b = j; b < p[i].size(); b++) {
            if (!haveApple) {
                for (int a = i; a < p.size(); a++) {
                    if (p[a][b] == 'A') {
                        haveApple = true;
                        break;
                    }
                }
            }
            
            if (haveApple) {
                answer += dfs(p, i, b + 1, k - 1);
                answer %= MOD;
            }
        }
        
        return f[i][j][k] = answer;
    }
};
