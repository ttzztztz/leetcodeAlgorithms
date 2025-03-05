class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            const int mid = (l + r) / 2;

            if (cnt(nums, mid) < k) r = mid - 1;
            else l = mid + 1;
        }

        return r;
    }
private:
    int cnt(const vector<int>& nums, int ans) {
        int cur = 0;
        for (int i : nums) {
            if (i >= ans) cur++;
        }
        return cur;
    }
};