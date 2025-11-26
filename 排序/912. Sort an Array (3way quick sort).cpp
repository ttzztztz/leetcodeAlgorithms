class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;

        sort_arr(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void sort_arr(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        const int pivot = nums[(l + r) / 2];
        int lt = l, gt = r, cur = l;
        while (cur <= gt) {
            if (nums[cur] < pivot) {
                swap(nums[lt], nums[cur]);
                lt++, cur++;
            } else if (nums[cur] == pivot) {
                cur++;
            } else {
                swap(nums[gt], nums[cur]);
                gt--;
            }
        }

        sort_arr(nums, l, lt - 1);
        sort_arr(nums, gt + 1, r);
    }
};