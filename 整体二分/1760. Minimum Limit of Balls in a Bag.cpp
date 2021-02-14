class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (solve(nums, mid) <= maxOperations) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    int solve(const vector<int>& nums, int mx) {
        int ans = 0;
        for (int i : nums) {
            const int t = i / mx;
            if (i % mx == 0) ans += max(0, i / mx - 1);
            else ans += max(0, i / mx);
        }
        return ans;
    }
};
