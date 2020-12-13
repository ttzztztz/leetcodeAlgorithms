class Solution {
public:
    /**
     * @param A: the array A[] in this problem
     * @return: return the minimum distance
     */
    long long arrayDistance(vector<int> &A) {
        // write your code here
        for (int i : A) all.push_back(i);
        sort(all.begin(), all.end());
        it = unique(all.begin(), all.end());
        for (int& i : A) i = lower_bound(all.begin(), it, i) - all.begin();
        memset(f, 0x3f, sizeof f);
        memset(g, 0x3f, sizeof g);
        
        ll ans = numeric_limits<ll>::max();
        const int n = A.size(), m = it - all.begin();
        for (int j = 0; j < m; j++) {
            f[0][j] = abs(all[j] - all[A[0]]);

            g[0][j] = f[0][j];
            if (j >= 1) g[0][j] = min(g[0][j], g[0][j - 1]);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i][j] = min(f[i][j], g[i - 1][j] + abs(all[j] - all[A[i]]));

                g[i][j] = f[i][j];
                if (j >= 1) g[i][j] = min(g[i][j], g[i][j - 1]);
            }
        }
        
        for (int j = 0; j < m; j++) ans = min(ans, f[n - 1][j]);
        return ans;
    }
private:
    typedef long long ll;
    ll f[1005][1005], g[1005][1005];
    vector<int> all;
    vector<int>::iterator it;
};
