class Solution {
public:
    int longestMountain(vector<int>& A) {
        const int n = A.size();
        vector<int> f(n, 1), g(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) f[i] = f[i - 1] + 1;
            else f[i] = 1;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1]) g[i] = g[i + 1] + 1;
            else g[i] = 1;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] >= 2 && g[i] >= 2) ans = max(ans, f[i] + g[i] - 1);
        }
        return ans;
    }
};