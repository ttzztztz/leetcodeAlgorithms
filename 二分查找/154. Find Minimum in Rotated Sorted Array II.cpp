class Solution {
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();

        int left = 0, right = N - 1;
        if (nums.size() == 1 || nums[0] < nums[N - 1]) {
            return nums[0];
        }

        while (left < right) {
            const int middle = (left + right) >> 1;

            if (nums[middle] > nums[right]) {
                left = middle + 1;
            } else if (nums[middle] < nums[right]) {
                right = middle;
            } else {
                right--;
            }
        }

        return nums[right];
    }
};