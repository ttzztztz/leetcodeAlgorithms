class Solution {
public:
    /**
     * @param num: sequence
     * @return: The longest valley sequence
     */
    int valley(vector<int> &num) {
        const int n = num.size();
        vector<int> f(n, 0), g(n, 0);
        
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (num[j] > num[i]) f[i] = max(f[i], f[j] + 1);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            g[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (num[j] > num[i]) g[i] = max(g[i], g[j] + 1);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (num[i] == num[j]) ans = max(ans, 2 * min(f[i], g[j]));
            }
        }
        return ans;
    }
};
