typedef long long ll;
ll f[1001][250];
bool va[250][250];

class Solution {
public:
    int colorTheGrid(int n, int m) {
        memset(f, 0xff, sizeof f);
        memset(va, 0, sizeof va);
        
        this->n = n, this->m = m;
        for (int i = 0; i < pow(3, n); i++) {
            if (ok(i)) valid.push_back(i);
        }
        
        for (int i : valid) {
            vector<int> prev = parse(i);
            for (int j : valid) {
                vector<int> cur = parse(j);
                bool ok = true;
                for (int t = 0; t < n; t++) {
                    if (prev[t] == cur[t]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    va[i][j] = true;
                }
            }
        }
        
        ll ans = 0;
        for (int i : valid) {
            ans = (ans + dfs(1, i)) % mod;
        }
        return ans;
    }
private:
    const int mod = 1e9+7;
    
    int n, m;
    vector<int> valid;
    vector<int> parse(int s) {
        vector<int> colors(n);
        int idx = 0;
        while (s) {
            colors[idx++] = s % 3;
            s /= 3;
        }
        return colors;
    }
    
    bool ok(int s) {
        vector<int> colors = parse(s);
        for (int i = 1; i < n; i++) {
            if (colors[i - 1] == colors[i]) return false;
        }
        return true;
    }
    
    ll dfs(int idx, int last) {
        if (idx == m) return 1;
        ll& val = f[idx][last];
        if (val != -1) return val;
        
        ll ans = 0;
        for (int i : valid) {
            if (va[last][i]) ans = (ans + dfs(idx + 1, i)) % mod;
        }
        return val = ans;
    }
};