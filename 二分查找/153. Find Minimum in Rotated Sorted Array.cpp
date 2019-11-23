class Solution {
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 3) {
            int answer = 999999;
            for (int i = 0; i < N; i++) {
                answer = min(answer, nums[i]);
            }
            return answer;
        }
        int left = 1, right = N - 2, pivot = -1;
        while (left <= right) {
            const int middle = (left + right) >> 1;
            const int l = nums[middle - 1], r = nums[middle + 1];

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
            return nums[0];
        }
        const int leftMin = nums[0], rightMin = nums[pivot];
        return min(leftMin, rightMin);
    }
};