class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        int ans = 0;

        vector<int> f(m + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> g(m + 1, 0);
            for (int j = m - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) g[j] = f[j + 1] + 1;
                else g[j] = 0;
                
                ans = max(ans, g[j]);
            }
            f = move(g);
        }
        
        return ans;
    }
};
