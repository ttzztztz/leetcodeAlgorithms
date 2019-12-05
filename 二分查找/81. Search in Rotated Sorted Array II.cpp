class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() <= 3) {
            for (int num : nums) {
                if (num == target) {
                    return true;
                }
            }

            return false;
        }

        const int N = nums.size();
        int left = 0, right = N - 1, pivot = -1;
        while (left <= right) {
            const int middle = (left + right) >> 1;
            const int l = middle - 1 >= 0 ? nums[middle - 1] : -999999;
            const int r = middle + 1 < N ? nums[middle + 1] : 9999999;

            if (nums[middle] < l && nums[middle] <= r) {
                pivot = middle;
                break;
            } else if (nums[middle] >= l && nums[middle] > r) {
                pivot = middle + 1;
                break;
            } else if (nums[left] == nums[middle] && nums[middle] == nums[right]) {
                left++;
            } else if (nums[left] <= nums[middle]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        if (pivot == -1) {
            pivot = N - 1;
        }
        const int left1 = 0, left2 = pivot, right1 = pivot - 1, right2 = N - 1;

        if (target == nums[left1] || target == nums[left2] || target == nums[right1] || target == nums[right2]) {
            return true;
        }

        if (target >= nums[left1] && target <= nums[right1]) {
            left = left1, right = right1;
            while (left <= right) {
                const int middle = (left + right) >> 1;
                if (nums[middle] < target) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }

            if (left < right1 && nums[left] == target) {
                return true;
            }
        }

        if (target >= nums[left2] && target <= nums[right2]) {
            left = left2, right = right2;
            while (left <= right) {
                const int middle = (left + right) >> 1;
                if (nums[middle] < target) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
            if (left < right2 && nums[left] == target) {
                return true;
            }
        }

        return false;
    }
};