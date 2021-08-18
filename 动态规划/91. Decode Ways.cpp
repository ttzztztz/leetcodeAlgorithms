class Solution {
public:
    int numDecodings(string s) {
        this->s = s;
        n = s.size();
        
        memset(f, 0xff, sizeof f);
        return dfs(0, 0);
    }
private:
    string s;
    int n;
    
    int f[101][4];
    int dfs(int idx, int last) {
        if (idx == n) return (last == 0);
        int& val = f[idx][last];
        if (val != -1) return val;
        
        int ans = 0;
        const int d = s[idx] - '0';
        if (last == 0 && (d == 1 || d == 2)) ans = (ans + dfs(idx + 1, d));
        if (last == 1) ans = (ans + dfs(idx + 1, 0));
        if (last == 2 && (0 <= d && d <= 6)) ans = (ans + dfs(idx + 1, 0));
        if (last == 0 && d != 0) ans = (ans + dfs(idx + 1, 0));
        return val = ans;
    }
};
