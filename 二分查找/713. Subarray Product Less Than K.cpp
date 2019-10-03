class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        double sum[nums.size() + 1];
        std::memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i - 1] + log(nums[i - 1]);
        }
        double logK = log(k);
        int answer = 0;

        for (int leftPtr = 1; leftPtr <= nums.size(); leftPtr++) {
            double willFind = sum[leftPtr - 1] + logK - 1e-9;

            double* binarySearch = std::lower_bound(sum, sum + nums.size(), willFind);
            int rightPtr = binarySearch - sum;
            while (leftPtr <= rightPtr && binarySearch >= sum && *binarySearch >= willFind) {
                binarySearch--;
                rightPtr--;
            }

            if (leftPtr <= rightPtr) {
                answer += rightPtr - leftPtr + 1;
            }
        }

        return answer;
    }
};