class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        this->n = n, this->evil = evil;
        build_kmp(evil);
        
        if (s1 > s2) return 0;
        ll lower = solve(s1), upper = solve(s2);
        ll ans = upper - lower;
        if (s1.find(evil) == string::npos) ans++;
        return (ans + mod) % mod;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    ll f[505][55][2];
    int nxt[55], n;
    string evil, s;
    
    ll solve(const string& str) {
        memset(f, 0xff, sizeof f);
        s = str;
        return dfs(0, 0, 0);
    }
    
    ll dfs(int idx, int j, int is_small) {
        if (j == evil.size()) return 0;
        if (idx == s.size()) return 1;
        
        ll& val = f[idx][j][is_small];
        if (val != -1) return val;
        
        ll ans = 0;
        
        for (char c = 'a'; c <= 'z'; c++) {
            if (!is_small && c > s[idx]) break;
            int nj = j;
            while (!(nj == -1 || c == evil[nj])) {
                nj = nxt[nj];
            }
            nj++;
            ans = (ans + dfs(idx + 1, nj, is_small || c < s[idx])) % mod;
        }
        return val = ans;
    }
    
    void build_kmp(const string& str) {
        memset(nxt, 0xff, sizeof nxt);
        nxt[1] = 0;
        int i = 1, j = 0;
        const int n = str.size();
        while (i < n) {
            if (j == -1 || str[i] == str[j]) {
                nxt[++i] = ++j;
            } else {
                j = nxt[j];
            }
        }
    }
};