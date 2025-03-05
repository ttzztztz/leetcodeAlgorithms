class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        return quick_select(nums, 0, n - 1, n - k);
    }
private:
    int quick_select(vector<int>& nums, int l, int r, int k) {
        if (l > r) return -1;

        const int pivot = nums[(l + r) / 2];
        int lt = l, gt = r, cur = l;
        while (cur <= gt) {
            if (nums[cur] < pivot) {
                swap(nums[cur], nums[lt]);
                cur++, lt++;
            } else if (nums[cur] == pivot) {
                cur++;
            } else { // nums[cur] > pivot
                swap(nums[cur], nums[gt]);
                gt--;
            }
        }

        if (k < lt) return quick_select(nums, l, lt - 1, k);
        else if (k > gt) return quick_select(nums, gt + 1, r, k);
        return pivot;
    }
};