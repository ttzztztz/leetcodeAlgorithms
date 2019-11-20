class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }

        const int N = nums.size();
        int left = 0, right = 0, currentSum = nums[0];
        int answer = 99999999;

        while (right < N) {
            if (left > right) {
                right++;
                if (right < N) {
                    currentSum += nums[right];
                }

                continue;
            }

            if (currentSum >= s) {
                answer = min(answer, right - left + 1);
                currentSum -= nums[left];
                left++;
            } else if (currentSum < s) {
                right++;
                if (right < N) {
                    currentSum += nums[right];
                }
            }
        }

        return answer == 99999999 ? 0 : answer;
    }
};