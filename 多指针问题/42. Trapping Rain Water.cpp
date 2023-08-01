class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        const int n = height.size();

        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                ans += max(0, lmax - height[l]);
                lmax = max(lmax, height[l]);
                l++;
            } else {
                ans += max(0, rmax - height[r]);
                rmax = max(rmax, height[r]);
                r--;
            }
        }

        return ans;
    }
};