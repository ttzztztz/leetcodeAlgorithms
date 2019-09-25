class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<int>();
        }

        sort(nums.begin(), nums.end());
        vector<int> answer;
        int dp[nums.size() + 1], pre[nums.size() + 1], maxLen = 0, maxLenIndex = 0;
        std::memset(pre, 0xff, sizeof(pre));
        for (int i = 0; i <= nums.size(); i++) {
            dp[i] = 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (0 == nums[i] % nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        maxLenIndex = i;
                    }
                }
            }
        }

        int ptr = maxLenIndex;
        while (ptr != -1) {
            answer.push_back(nums[ptr]);
            ptr = pre[ptr];
        }

        return answer;
    }
};