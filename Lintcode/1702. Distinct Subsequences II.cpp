class Solution {
public:
    /**
     * @param S: The string s
     * @return: The number of distinct, non-empty subsequences of S.
     */
    int distinctSubseqII(string &S) {
        const int N = S.size();
        const int MOD = 1e9 + 7;
        vector<long long> f(N + 1, 0);
        vector<int> last(26, -1);
        
        f[0] = 1;
        for (int i = 1; i <= N; i++) {
            f[i] = f[i - 1] * 2;
            
            const int l = last[S[i - 1] - 'a'];
            if (l - 1 >= 0) f[i] -= f[l - 1];
            last[S[i - 1] - 'a'] = i;
            
            f[i] += MOD;
            f[i] %= MOD;
        }
        return (f[N] - 1 + MOD) % MOD;
    }
};
