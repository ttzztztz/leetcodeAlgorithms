class Solution {
public:
    int binarySearch(const vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int middle = (left + right) >> 1;

            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        } else if (nums.size() <= 3) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }

        const int N = nums.size();
        int left = 1, right = N - 2, pivot = -1;
        while (left <= right) {
            int middle = (left + right) >> 1;
            const int l = nums[middle - 1];
            const int r = nums[middle + 1];

            if (nums[middle] < l && nums[middle] < r) {
                pivot = middle;
                break;
            } else if (nums[middle] > l && nums[middle] > r) {
                pivot = middle + 1;
                break;
            } else if (nums[0] < nums[middle]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        if (pivot == -1) {
            return binarySearch(nums, 0, N - 1, target);
        }
        int block1Min = nums[0], block1Max = nums[pivot - 1];
        int block2Min = nums[pivot], block2Max = nums[N - 1];

        if (block1Min <= target && target <= block1Max) {
            return binarySearch(nums, 0, pivot - 1, target);
        } else if (block2Min <= target && target <= block2Max) {
            return binarySearch(nums, pivot, N - 1, target);
        } else {
            return -1;
        }
    }
};