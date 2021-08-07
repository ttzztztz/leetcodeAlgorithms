class Solution {
public:
    int minCut(string s) {
        this->s = s;
        n = s.size();
        f = vector<vector<int>>(n, vector<int>(n, -1));
        g = vector<int>(n, -1);
        
        return dfs(0) - 1;
    }
private:
    vector<vector<int>> f;
    vector<int> g;
    string s;
    int n;
    
    int is_palindrome(int i, int j) {
        if (i > j) return false;
        if (i == j) return true;
        if (i + 1 == j) return s[i] == s[j];
        
        int& val = f[i][j];
        if (val != -1) return val;
        
        int ans = 0;
        if (s[i] == s[j]) ans = is_palindrome(i + 1, j - 1);
        return val = ans;
    }
    
    int dfs(int idx) {
        if (idx == n) return 0;
        int& val = g[idx];
        if (val != -1) return val;
        
        int ans = n - idx;
        for (int j = idx; j < n; j++) {
            if (is_palindrome(idx, j)) ans = min(ans, 1 + dfs(j + 1));
        }
        return val = ans;
    }
};
