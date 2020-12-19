class Solution {
public:
    /**
     * @param A: the A array
     * @param B: the B array
     * @return: return the maxium inner product of B and C
     */
    long long getMaxInnerProduct(vector<int> &A, vector<int> &B) {
        // write your code here
        const int n = A.size(), k = B.size();
        typedef long long ll;
        vector<vector<ll>> memo(k + 1, vector<ll>(k + 1, 0));
        
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                if (i - 1 >= 0) {
                    memo[i][j] = max(memo[i][j], memo[i - 1][j] + 1ll * A[i - 1] * B[i + j - 1]);
                }
                
                if (j - 1 >= 0) {
                    memo[i][j] = max(memo[i][j], memo[i][j - 1] + 1ll * A[n - j] * B[i + j - 1]);
                }
            }
        }
        
        ll ans = 0;
        for (int i = 0; i <= k; i++) ans = max(ans, memo[i][k - i]);
        return ans;
    }
};
