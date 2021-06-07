class Solution {
public:
    int minFlips(string s) {
        const int n = s.size();
        
        int f[100005][2];
        memset(f, 0, sizeof f);
        f[0][0] = (s[0] != '0'), f[0][1] = (s[0] != '1');
        for (int i = 1; i < n; i++) {
            f[i][0] = f[i - 1][1] + (s[i] != '0');
            f[i][1] = f[i - 1][0] + (s[i] != '1');
        }
        
        auto query = [&](int r, int r_last) -> int {
            if (r < 0) return 0;
            return f[r][r_last];
        };
        int ans = n;
        for (int i = -1; i <= n; i++) {
            const int len1 = i + 1, len2 = n - i - 1;
            
            const int a = query(n - 1, 0) - query(i, (len2 % 2 == 0) ? 0 : 1) + query(i, (len1 % 2 == 1) ? 1 : 0);
            const int b = query(n - 1, 1) - query(i, (len2 % 2 == 0) ? 1 : 0) + query(i, (len1 % 2 == 1) ? 0 : 1);
            ans = min(ans, min(a, b));
        }
        return ans;
    }
};