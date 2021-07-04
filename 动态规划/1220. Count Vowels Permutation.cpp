class Solution {
public:
    int countVowelPermutation(int n) {
        this->n = n;
        memset(f, 0xff, sizeof f);
        if (n == 0) return 1;
        ll ans = 0;
        for (int i = 0; i <= 4; i++) ans = (ans + dfs(1, i)) % mod;
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    
    ll f[20005][6];
    int n;
    // 0 -> a, 1 -> e, 2 -> i, 3 -> o, 4 -> u
    vector<vector<int>> nxt = {
        { 1 },
        { 0, 2 },
        { 0, 1, 3, 4 },
        { 2, 4 },
        { 0 }
    };
    
    ll dfs(int idx, int last) {
        if (idx == n) return 1;
        ll& val = f[idx][last];
        if (val != -1) return val;
        
        ll ans = 0;
        for (int ne : nxt[last]) ans = (ans + dfs(idx + 1, ne)) % mod;
        return val = ans;
    }
};

class Solution {
public:
    int countVowelPermutation(int n) {
        if (n == 0) return 1;
        
        ll f[20005][6];
        memset(f, 0, sizeof f);
        
        for (int idx = n; idx >= 0; idx--) for (int last = 0; last <= 4; last++) {
            ll& val = f[idx][last];
            if (idx == n) {
                val = 1;
                continue;
            }

            for (int ne : nxt[last]) {
                val = (val + f[idx + 1][ne]) % mod;
            }
        }
        
        ll ans = 0;
        for (int i = 0; i <= 4; i++) ans = (ans + f[1][i]) % mod;
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    
    // 0 -> a, 1 -> e, 2 -> i, 3 -> o, 4 -> u
    vector<vector<int>> nxt = {
        { 1 },
        { 0, 2 },
        { 0, 1, 3, 4 },
        { 2, 4 },
        { 0 }
    };
};