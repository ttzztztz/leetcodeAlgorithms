class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        
        vector<vector<int>> f(n + 1, vector<int>(m + 1, numeric_limits<int>::min() / 2));
        for (int i = n; i >= 0; i--) for (int j = m; j >= 0; j--) {
            if (i == n || j == m) {
                f[i][j] = 0;
                continue;
            }
            
            f[i][j] = max(max(f[i + 1][j + 1] + nums1[i] * nums2[j], f[i][j + 1]), f[i + 1][j]);
        }
        
        int ans = numeric_limits<int>::min();
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            ans = max(ans, nums1[i] * nums2[j] + f[i + 1][j + 1]);
        }
        return ans;
    }
};