class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        init();
        return dfs(destination[1], destination[0], k - 1);
    }
private:
    string dfs(int h, int v, int k) {
        if (h == 0) {
            return string(v, 'V');
        } else if (v == 0) {
            return string(h, 'H');
        }
        
        const int p = f[h + v - 1][v];
        // place h
        if (k < p) {
            return "H" + dfs(h - 1, v, k);
        } else { // place v
            return "V" + dfs(h, v - 1, k - p);
        }
    }
    
    typedef long long ll;
    ll f[35][35];
    void init() {
        memset(f, 0, sizeof f);
        for (int i = 0; i <= 30; i++) f[i][0] = f[0][i] = 1;
        f[0][0] = 0;
        
        for (int i = 1; i <= 30; i++) {
            for (int j = 1; j <= i; j++) {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            }
        }
    }
};
