class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int n = jobDifficulty.size();
        vector<int> f(n + 1, 9999999);
        
        for (int i = d; i >= 0; i--) {
            for (int j = 0; j <= n; j++) {
                f[j] = 9999999;
                if (i == d) {
                    f[j] = (j == n) ? 0 : 9999999;
                    continue;
                }
                if (j == n) continue;
                
                int mx = jobDifficulty[j];
                for (int k = j + 1; k <= n; k++) {
                    f[j] = min(f[j], mx + f[k]);
                    if (k < n) mx = max(mx, jobDifficulty[k]);
                }
            }
        }
        
        if (f[0] >= 9999999) return -1;
        else return f[0];
    }
};