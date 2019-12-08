class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();
        int left = 0, right = N - 1;
        while (left <= right) {
            const int middle = (left + right) >> 1;

            if (nums[middle] == target) {
                return middle;
            }

            if (nums[left] <= nums[middle]) {
                if (nums[left] <= target && target <= nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                if (nums[middle] <= target && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }

        return -1;
    }
};