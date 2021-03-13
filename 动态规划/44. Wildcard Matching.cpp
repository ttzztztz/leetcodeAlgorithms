class Solution {
public:
    bool isMatch(string s, string p) {
        this->s = s, this->p = p;
        f = vector<vector<int>>(s.size() + 5, vector<int>(p.size() + 5, -1));
        return dfs(0, 0);
    }
private:
    string s, p;
    vector<vector<int>> f;
    
    int dfs(int i, int j) {
        if (j == p.size() + 1) {
            return i == s.size() + 1;
        }
        if (j > p.size() || i > s.size()) {
            return false;
        }

        int& val = f[i][j];
        if (val != -1) return val;

        int ans = 0;
        if (p[j] == '?' || s[i] == p[j]) {
            ans |= dfs(i + 1, j + 1);
        }
        if (p[j] == '*') {
            ans |= dfs(i, j + 1) | dfs(i + 1, j) | dfs(i + 1, j + 1);
        }
        return val = ans;
    }
};