class Solution {
public:
    int calcSum(vector<int>& nums, int divisor) {
        int answer = 0;
        for (int num : nums) {
            answer += num / divisor;
            if (num % divisor) {
                answer ++;
            }
        }
        return answer;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxNumber = -1;
        for (int num : nums) {
            maxNumber = max(num, maxNumber);
        }

        int left = 1, right = maxNumber;
        while (left <= right) {
            const int middle = (left + right) >> 1;

            if (calcSum(nums, middle) > threshold) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return left;
    }
};