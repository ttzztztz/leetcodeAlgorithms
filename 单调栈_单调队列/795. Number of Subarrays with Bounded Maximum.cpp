class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        const int n = A.size();
        vector<int> f(n + 1, 0), g(n + 1, 0);
        
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && A[stk.back()] <= A[i]) stk.pop_back();
            
            if (stk.empty()) f[i] = -1;
            else f[i] = stk.back();
            
            stk.push_back(i);
        }
        
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && A[stk.back()] < A[i]) stk.pop_back();
            
            if (stk.empty()) g[i] = n;
            else g[i] = stk.back();

            stk.push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (L <= A[i] && A[i] <= R) {
                const int l = i - f[i], r = g[i] - i;
                
                ans += l * r;
            }
        }
        return ans;
    }
};
