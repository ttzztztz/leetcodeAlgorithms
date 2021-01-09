class Solution {
public:
    int maxA(int n) {
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            f[i] = i;
            
            for (int k = 0; i - k - 1 >= 1 && k < i; k++) {
                f[i] = max(f[i], f[k] * (i - k - 1));
            }
        }
        return f[n];
    }
};
