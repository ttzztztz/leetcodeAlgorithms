class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        const int n = A.size();
        typedef long long ll;
        ll ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            ans += i * A[i]; // calc F[0]
            sum += A[i];
        }
        
        ll f_last = ans;
        for (int i = 1; i < n; i++) {
            const int last_idx = n - i;
            f_last = (f_last - (n - 1) * A[last_idx]) + (sum - A[last_idx]);
            ans = max(ans, f_last);
        }
        return ans;
    }
};
