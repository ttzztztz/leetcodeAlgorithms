class Solution {
public:
    int minimumDeletions(string s) {
        memset(f, 0xff, sizeof f);
        this->s = s;
        this->n = s.size();
        
        return min((s[0] == 'b') + dfs(1, 0), (s[0] == 'a') + dfs(1, 1));
    }
private:
    int f[100005][2];
    string s;
    int n;
    
    int dfs(int i, int last) {
        if (i == n) return 0;
        int& val = f[i][last];
        if (val != -1) return val;
        int ans = n + 5;
        if (last == 0) { // a
            if (s[i] == 'a') ans = min(ans, dfs(i + 1, 0));
            else ans = min(1 + dfs(i + 1, 0), dfs(i + 1, 1));
        } else { // b
            if (s[i] == 'b') ans = min(ans, dfs(i + 1, 1));
            else ans = min(ans, 1 + dfs(i + 1, 1));
        }
        
        return val = ans;
    }
};
