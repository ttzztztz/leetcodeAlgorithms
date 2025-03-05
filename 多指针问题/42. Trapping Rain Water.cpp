class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n <= 1) return 0;

        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = height[0], rmax = height[n - 1];
        while (l < r) {
            if (height[l] <= height[r]) {
                l++;
                if (l < n) {
                    lmax = max(lmax, height[l]);
                    ans += lmax - height[l];
                }
            } else {
                r--;
                if (r >= 0) {
                    rmax = max(rmax, height[r]);
                    ans += rmax - height[r];
                }
            }
        }
        return ans;
    }
};