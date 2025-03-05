class Solution {
public:
    bool isMatch(string s, string p) {
        const int n = s.size(), m = p.size();
        memo = vector<vector<int>>(n, vector<int>(m, -1));
        return dfs(s, p, 0, 0);
    }
private:
    vector<vector<int>> memo;

    bool can_terminate(const string& p, int j) {
        while (j < p.size()) {
            if (!(j + 1 < p.size() && p[j + 1] == '*')) {
                return false;
            }
            j += 2;
        }
        return true;
    }

    bool dfs(const string& s, const string& p, int i, int j) {
        if (i >= s.size()) return can_terminate(p, j);
        if (j >= p.size()) return i >= s.size();
        if (memo[i][j] != -1) return memo[i][j];

        bool ans = false;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans = ans || dfs(s, p, i, j + 2);

            if (p[j] == '.' || p[j] == s[i]) {
                ans = ans || dfs(s, p, i + 1, j) || dfs(s, p, i + 1, j + 2);
            }
        } else {
            if (p[j] == '.' || p[j] == s[i]) {
                ans = ans || dfs(s, p, i + 1, j + 1);
            }
        }
        return memo[i][j] = ans;
    }
};