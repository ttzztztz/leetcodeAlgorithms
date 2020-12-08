class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        const int n = A.size();
        vector<int> f(n), g(n);
        f[0] = A[0], g[n - 1] = A[n - 1];
        for (int i = 1; i < n; i++) f[i] = max(f[i - 1], A[i]);
        for (int i = n - 2; i >= 0; i --) g[i] = min(g[i + 1], A[i]);
        
        for (int i = 0; i + 1 < n; i++) {
            if (f[i] <= g[i + 1]) return i + 1;
        }
        return n - 1;
    }
};
