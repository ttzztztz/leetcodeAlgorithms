class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans = 0;
        const int n = A.size();
        
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || A[stk.back()] > A[i]) {
                stk.push_back(i);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && A[i] >= A[stk.back()]) {
                ans = max(ans, i - stk.back());
                stk.pop_back();
            }
        }
        return ans;
    }
};
