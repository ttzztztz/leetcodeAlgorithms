class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        const int n = A.size();
        vector<int> pref = {0};
        for (int i : A) pref.push_back(pref.back() + i);
        
        int ans = 0;
        int Lmax = pref[L], Mmax = pref[M];
        for (int i = L + M; i <= n; i++) {
            Lmax = max(Lmax, pref[i - M] - pref[i - M - L]);
            Mmax = max(Mmax, pref[i - L] - pref[i - M - L]);
            
            ans = max(ans, max(
                Lmax + pref[i] - pref[i - M],
                Mmax + pref[i] - pref[i - L]
            ));
        }
        
        return ans;
    }
};
