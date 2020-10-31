int f[300005][2][2][2][2];

class Solution {
public:
    /**
     * @param s: a string only contains `a-f`
     * @return: The longest length that satisfies the condition
     */
    int conditionString(string &s) {
        // write your code here
        const int n = s.size();
        this->s = s;
        memset(f, 0xff, sizeof f);
        
        int ans = 0;
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                for (int c = 0; c <= 1; c++) {
                    for (int d = 0; d <= 1; d++) {
                        ans = max(ans, n - dfs(0, a, b, c, d));
                    }
                }
            }
        }
        return ans;
    }
private:
    string s;
    int dfs(int idx, int a, int b, int c, int d) {
        if (idx == s.size()) return 0;
        int& val = f[idx][a][b][c][d];
        if (val != -1) return val;
        
        int ans = numeric_limits<int>::max();
        if (s[idx] == 'a') {
            if (a == 1) ans = min(ans, 1 + dfs(idx + 1, a, b, c, d));
            else ans = min(ans, min(dfs(idx + 1, a, b, c, d), dfs(idx + 1, 1, b, c, d)));
        } else if (s[idx] == 'b') {
            if (b == 1) ans = min(ans, 1 + dfs(idx + 1, a, b, c, d));
            else ans = min(ans, min(dfs(idx + 1, a, b, c, d), dfs(idx + 1, a, 1, c, d)));
        } else if (s[idx] == 'c') {
            if (a == 0) {
                ans = min(ans, 1 + dfs(idx + 1, a, b, c, d));
            } else { // a == 1
                if (c == 1) {
                    ans = min(ans, 1 + dfs(idx + 1, a, b, c, d));
                } else { // c == 0
                    ans = min(ans, min(dfs(idx + 1, a, b, c, d), dfs(idx + 1, a, b, 1, d)));
                }
            }
        } else if (s[idx] == 'd') {
            if (b == 0) {
                ans = min(ans, 1 + dfs(idx + 1, a, b, c, d));
            } else { // b == 1
                if (d == 1) {
                    ans = min(ans, 1 + dfs(idx + 1, a, b, c, d));
                } else { // d == 0
                    ans = min(ans, min(dfs(idx + 1, a, b, c, d), dfs(idx + 1, a, b, c, 1)));
                }
            }
        } else if (s[idx] == 'e') {
            if (a == 1 && c == 1) ans = min(ans, dfs(idx + 1, a, b, c, d));
            else ans = min(ans, 1 + dfs(idx + 1, a, b, c, d));
        } else if (s[idx] == 'f') {
            if (b == 1 && d == 1) ans = min(ans, dfs(idx + 1, a, b, c, d));
            else ans = min(ans, 1 + dfs(idx + 1, a, b, c, d));
        }
        return val = ans;
    }
};
