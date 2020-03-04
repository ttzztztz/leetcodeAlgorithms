class Solution {
public:
    /**
     * @param steps: steps you can move
     * @param arrLen: the length of the array
     * @return: Number of Ways to Stay in the Same Place After Some Steps
     */
    int numWays(int steps, int arrLen) {
        if (arrLen > steps) arrLen = min(steps, arrLen);
        
        const int MOD = 1e9+7;
        vector<long long> f(arrLen + 1, 0);
        f[0] = 1;
        
        for (int i = 0; i < steps; i++) {
            vector<long long> g(arrLen + 1, 0);
            
            for (int j = 0; j <= arrLen; j++) {
                g[j] += f[j];
                g[j] %= MOD;
                if (j + 1 < arrLen) g[j] += f[j + 1];
                g[j] %= MOD;
                if (j - 1 >= 0) g[j] += f[j - 1];
                g[j] %= MOD;
            }
            
            f = g;
        }
        
        return f[0];
    }
};
