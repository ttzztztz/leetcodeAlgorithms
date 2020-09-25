class Solution {
public:
    /**
     * @param ring: a string
     * @param key: a string
     * @return: return a integer
     */
    int findRotateSteps(string &ring, string &key) {
        // write your code here
        this->r = ring, this->k = key;
        memset(f, 0xff, sizeof f);
        
        return dfs(0, 0);
    }
private:
    int f[105][105];
    string r, k;
    int dfs(int i, int j) {
        if (j == k.size()) return 0;
        int& val = f[i][j];
        if (val != -1) return val;
        
        int ans = numeric_limits<int>::max();
        if (r[i] == k[j]) {
            ans = 1 + dfs(i, j + 1);
        } else {
            for (int x = 0; x < r.size(); x++) {
                const int idx = (i + x) % r.size();
                if (r[idx] == k[j]) ans = min(ans, dfs(idx, j + 1) + x + 1);
            }
            
            for (int x = 0; x < r.size(); x++) {
                const int idx = (i - x + r.size()) % r.size();
                if (r[idx] == k[j]) ans = min(ans, dfs(idx, j + 1) + x + 1);
            }
        }
        return val = ans;
    }
};
