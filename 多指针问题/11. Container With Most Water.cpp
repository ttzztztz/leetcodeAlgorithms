class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[r], height[l]));

            if (height[l] <= height[r]) l++;
            else r--;
        }
        return ans;
    }
};