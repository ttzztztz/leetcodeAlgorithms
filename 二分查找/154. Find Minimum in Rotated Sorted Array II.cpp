class Solution {
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();

        int left = 0, right = N - 1;
        while (left <= right) {
            cout << left << " " << right << endl;
            while (left + 1 <= right && nums[left + 1] == nums[left]) {
                left++;
            }
            while (right - 1 >= left && nums[right] == nums[right - 1]) {
                right--;
            }

            const int middle = (left + right) >> 1;
            if (middle - 1 >= 0 && nums[middle] < nums[middle - 1]) {
                return min(nums[0], nums[middle]);
            }

            if (nums[0] <= nums[middle]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return nums[0];
    }
};