class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int number = nums[i];

            if (number > stack.back()) {
                stack.push_back(number);
            } else if (number < stack.back()) {
                auto it_self = std::lower_bound(stack.begin(), stack.end(), number);
                if (*it_self != number) {
                    auto it = std::upper_bound(stack.begin(), stack.end(), number);
                    *it = number;
                }
            }
        }

        return stack.size();
    }
};