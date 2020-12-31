class Solution {
public:
    /**
     * @param k1: The coefficient of A
     * @param k2: The  coefficient of B
     * @param c: The volume of backpack
     * @param n: The amount of A
     * @param m: The amount of B
     * @param a: The volume of A
     * @param b: The volume of B
     * @return: Return the max value you can get
     */
    long long getMaxValue(int k1, int k2, int c, int n, int m, vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        long long f[1100][1100];
        long long pa[1100], pb[1100];
        
        memset(f, 0, sizeof f);
        memset(pa, 0, sizeof pa);
        memset(pb, 0, sizeof pb);
        
        for (int i = 1; i <= n; i++) {
            pa[i] = pa[i - 1] + a[i - 1];
        }
        
        for (int i = 1; i <= m; i++) {
            pb[i] = pb[i - 1] + b[i - 1];
        }
        
        long long answer = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (pa[i] + pb[j] > c) continue;
                
                long long rest = 1ll * c - pa[i] - pb[j];
                f[i][j] = max(
                    (i - 1 >= 0 ? (f[i - 1][j] + + 1ll * k1 * rest) : 0),
                    (j - 1 >= 0 ? (f[i][j - 1] + + 1ll * k2 * rest) : 0)
                );
                
                answer = max(answer, f[i][j]);
            }
        }
        return answer;
    }
};
