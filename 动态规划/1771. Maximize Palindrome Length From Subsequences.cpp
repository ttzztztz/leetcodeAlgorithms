int f[2005][2005][2][2];

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        t = word1 + word2;
        n = word1.size(), m = word2.size();
        memset(f, 0xff, sizeof f);
        
        return max(0, dfs(0, n + m - 1, 0, 0));
    }
private:
    string t;
    int n, m;
    
    int dfs(int i, int j, int p1, int p2) {
        if (i == j) {
            // cout << p1 << "," << p2 << endl;
            return (p1 && p2) ? 1 : -999999;
        }
        if (i > j) {
            // cout << p1 << "," << p2 << endl;
            return (p1 && p2) ? 0 : -999999;
        }
        int& val = f[i][j][p1][p2];
        if (val != -1) return val;
        
        int ans = -999999;
        if (t[i] == t[j]) {
            int np1 = p1 || i < n || j < n;
            int np2 = p2 || i >= n || j >= n;

            ans = max(ans, 2 + dfs(i + 1, j - 1, np1, np2));
        } else {
            ans = max(ans, max(dfs(i, j - 1, p1, p2), dfs(i + 1, j, p1, p2)));
        }
        return val = ans;
    }
};
