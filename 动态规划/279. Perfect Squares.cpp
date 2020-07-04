class Solution {
public:
    int numSquares(int n) {
        vector<int> all;
        for (int i = 1; i * i <= n; i++) all.push_back(i * i);
        
        int f[n + 5];
        memset(f, 0, sizeof f);
        for (int i = 0; i <= n; i++) f[i] = i;
        for (int i = 1; i < all.size(); i++) {
            for (int j = all[i]; j <= n; j++) {
                f[j] = min(f[j], f[j - all[i]] + 1);
            }
        }
        
        return f[n];
    }
};
