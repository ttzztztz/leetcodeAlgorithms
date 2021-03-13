class Solution {
public:
    bool isMatch(string s, string p) {
        f = vector<vector<int>>(s.size() + 5, vector<int>(p.size() + 5, -1));
        this->s = s, this->p = p;
        
        return dfs(0, 0);
    }
private:
    vector<vector<int>> f;
    string s, p;
    
    int dfs(int i, int j) {
        if (j == p.size() + 1) {
            return i == s.size() + 1;
        }
        if (i > s.size() || j > p.size()) {
            return false;
        }
        int& val = f[i][j];
        if (val != -1) return val;
        
        int ans = 0;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans |= dfs(i, j + 2);
            if (p[j] == '.' || s[i] == p[j]) {
                ans |= dfs(i + 1, j + 2) || dfs(i + 1, j);
            }
        }

        if (p[j] == '.' || s[i] == p[j]) {
            ans |= dfs(i + 1, j + 1);
        }
        return val = ans;
    }
};