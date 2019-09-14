class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return vector<int>();
        }

        int N = nums.size();
        int dp_left[N + 1], dp_right[N + 1];
        std::memset(dp_left, 0, sizeof(dp_left));
        std::memset(dp_right, 0, sizeof(dp_right));

        int blockCount = (N % k) == 0 ? (N / k) : (N / k + 1);
        for (int i = 0; i < blockCount; i++) {
            int base = i * k;

            int leftMaxNumber = 1 << 32 - 1, rightMaxNumber = 1 << 32 - 1;
            for (int i = base; i < base + k && i < N; i++) {
                leftMaxNumber = std::max(nums[i], leftMaxNumber);
                dp_left[i] = leftMaxNumber;
            }

            for (int i = std::min(base + k - 1, N - 1); i >= base; i--) {
                rightMaxNumber = std::max(nums[i], rightMaxNumber);
                dp_right[i] = rightMaxNumber;
            }
        }

        vector<int> answer;
        for (int i = 0; i + k - 1 < N; i++) {
            int j = i + k - 1;
            answer.push_back(std::max(dp_right[i], dp_left[j]));
        }
        return answer;
    }
};