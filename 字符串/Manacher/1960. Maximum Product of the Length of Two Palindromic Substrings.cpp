class Solution {
public:
    long long maxProduct(string s) {
        typedef long long ll;
        const int n = s.size();
        
        vector<int> m(n + 1, 0);
        int center = 0, right = 0;
        for (int i = 0; i < n; i++) {
            int& r = m[i];
            
            if (right > i) r = min(right - i, m[2 * center - i]);
            while (i - r >= 0 && i + r < n && s[i - r] == s[i + r]) r++;
            
            if (i + r > right) {
                center = i, right = i + r;
            }
        }
        
        vector<ll> f(n + 1, 0), g(n + 1, 0);
        for (int i = 0; i < n; i++) {
            f[i + m[i] - 1] = max<ll>(f[i + m[i] - 1], m[i] * 2 - 1);
            g[i - m[i] + 1] = max<ll>(g[i - m[i] + 1], m[i] * 2 - 1);
        }
        
        for (int i = n - 2; i >= 0; i--) f[i] = max(f[i], f[i + 1] - 2);
        for (int i = 1; i < n; i++) g[i] = max(g[i], g[i - 1] - 2);
        
        for (int i = 1; i < n; i++) f[i] = max(f[i], f[i - 1]);
        for (int i = n - 2; i >= 0; i--) g[i] = max(g[i], g[i + 1]);
        
        ll ans = 0;
        for (int i = 0; i + 1 < n; i++) ans = max(ans, f[i] * g[i + 1]);
        return ans;
    }
};