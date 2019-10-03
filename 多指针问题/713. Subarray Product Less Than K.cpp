class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        int answer = 0;

        int leftPtr = 0, product = 1;
        for (int rightPtr = 0; rightPtr < nums.size(); rightPtr++) {
            product *= nums[rightPtr];

            while (product >= k) {
                product /= nums[leftPtr++];
            }

            answer += rightPtr - leftPtr + 1;
        }

        return answer;
    }
};