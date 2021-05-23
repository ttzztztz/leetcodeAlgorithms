class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int f[100005], g[100005];
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        f[0] = g[0] = 1;
        const int n = s.size();
        
        for (int i = 1; i < n; i++) {
            int l = 0, r = 0;
            if (i - maxJump >= 1) l = g[i - maxJump - 1];
            if (i - minJump >= 0) r = g[i - minJump];
            
            if (s[i] == '0' && r - l > 0) f[i] = 1;
            g[i] = g[i - 1] + f[i];
            
        }
        
        return f[n - 1];
    }
};