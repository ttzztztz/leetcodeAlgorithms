class Solution {
public:
    int numDecodings(string s) {
        memset(f, 0xff, sizeof f);
        str = s;
        
        return dfs(0, 0);
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    
    string str;
    ll f[100001][5];
    ll dfs(int idx, int last) {
        if (idx == str.size()) return (last == 0) ? 1 : 0;
        ll& val = f[idx][last];
        if (val != -1) return val;
        
        ll ans = 0;
        if (str[idx] == '*') {
            for (int d = 1; d <= 9; d++) {
                if (last == 0 && d != 0) ans = (ans + dfs(idx + 1, 0)) % mod;
                if (last == 0 && (d == 1 || d == 2)) ans = (ans + dfs(idx + 1, d)) % mod;
                if (last == 1) ans = (ans + dfs(idx + 1, 0));
                if (last == 2 && 0 <= d && d <= 6) ans = (ans + dfs(idx + 1, 0));
            }
        } else {
            const int d = str[idx] - '0';
            if (last == 0 && d != 0) ans = (ans + dfs(idx + 1, 0)) % mod;
            if (last == 0 && (d == 1 || d == 2)) ans = (ans + dfs(idx + 1, d)) % mod;
            if (last == 1) ans = (ans + dfs(idx + 1, 0));
            if (last == 2 && 0 <= d && d <= 6) ans = (ans + dfs(idx + 1, 0));
        }
        return val = ans;
    }
};