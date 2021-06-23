int f[501][501];

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> psum = {0};
        for (int i : stoneValue) {
            psum.push_back(psum.back() + i);
        }
        
        memset(f, 0, sizeof f);
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                for (int k = i; k + 1 <= j; k++) {
                    const int l = psum[k + 1] - psum[i], r = psum[j + 1] - psum[k + 1];
                    
                    if (l > r) {
                        f[i][j] = max(f[i][j], r + f[k + 1][j]);
                    } else if (l < r) {
                        f[i][j] = max(f[i][j], l + f[i][k]);
                    } else {
                        f[i][j] = max(f[i][j], max(f[i][k], f[k + 1][j]) + l);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};