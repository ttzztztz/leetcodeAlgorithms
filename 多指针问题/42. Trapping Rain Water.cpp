class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int ans = 0;
        const int n = height.size();
        for (int l = 0, r = n - 1, lval = height[0], rval = height[n - 1]; l < r;) {
            if (height[l] < height[r]) {
                ans += max(0, lval - height[l]);
                lval = max(lval, height[l]);
                l++;
            } else {
                ans += max(0, rval - height[r]);
                rval = max(rval, height[r]);
                r--;
            }
        }
        
        return ans;
    }
};
