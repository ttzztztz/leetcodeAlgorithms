class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        const int n = nums.size();
        int ans = n + 5;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        return ans;
    }
};