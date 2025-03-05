class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        const int n = s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return dfs(s, 0, n - 1) <= k;
    }
private:
    vector<vector<int>> memo;
    int dfs(const string& str, int i, int j) {
        if (i >= j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (str[i] == str[j]) return memo[i][j] = dfs(str, i + 1, j - 1);

        return memo[i][j] = 1 + min(dfs(str, i + 1, j), dfs(str, i, j - 1));
    }
};