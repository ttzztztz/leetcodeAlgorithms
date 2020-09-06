class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int N = nums.size();
        int left = 0, right = N - 1;
        while (left <= right) {
            while (left + 1 <= right && nums[left + 1] == nums[left]) {
                left++;
            }
            while (right - 1 >= left && nums[right - 1] == nums[right]) {
                right--;
            }

            const int middle = (left + right) >> 1;
            if (nums[middle] == target) {
                return true;
            }

            if (nums[left] <= nums[middle]) {
                if (nums[left] <= target && target < nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                if (nums[middle] < target && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        return false;
    }
};