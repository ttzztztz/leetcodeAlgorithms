double f[105][605];
bool g[105][605];

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        this->n = n;
        vector<pair<int, double>> ans;
        
        double ttl = 0;
        for (int k = n; k <= 6 * n; k++) {
            double cur = dfs(n, k);
            ttl += cur;
            ans.emplace_back(k, cur);
        }
        
        for (auto& p : ans) {
            p.second /= 1.0 * ttl;
        }
        return ans;
    }
private:
    int n;
    double dfs(int i, int cnt) {
        if (cnt < 0) return 0;
        if (i == 0) return cnt == 0 ? 1 : 0;
        
        double& val = f[i][cnt];
        bool& visited = g[i][cnt];
        if (visited) return val;
        
        double ans = 0;
        for (int k = 1; k <= 6; k++) {
            ans += dfs(i - 1, cnt - k);
        }
        return (visited = true, val = ans);
    }
};
