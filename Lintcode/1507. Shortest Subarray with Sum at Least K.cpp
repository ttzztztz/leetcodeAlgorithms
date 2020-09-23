class Solution {
public:
    /**
     * @param A: the array
     * @param K: sum
     * @return: the length
     */
    int shortestSubarray(vector<int> &A, int K) {
        int ans = 999999;
        const int n = A.size();
        typedef long long ll;
        vector<ll> sum = { 0 };
        for (int i = 0; i < n; i++) {
            sum.push_back(sum[i] + A[i]);
        }
        
        vector<int> stk;
        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && sum[stk.back()] >= sum[i]) stk.pop_back();
            
            int l = 0, r = stk.size() - 1;
            while (l <= r) {
                const int mid = (l + r) >> 1;
                const ll solve = sum[i] - sum[stk[mid]];
                    
                if (solve < K) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            
            if (r >= 0 && sum[i] - sum[stk[r]] >= K) ans = min(ans, i - stk[r]);
            stk.push_back(i);
        }
        
        if (ans == 999999) return -1;
        else return ans;
    }
};
