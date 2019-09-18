class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = 1 << 32 - 1;

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == last) {
                continue;
            }
            if (nums[i] > 0) {
                break;
            }

            int leftPtr = i + 1, rightPtr = nums.size() - 1;
            while (leftPtr < rightPtr) {
                int sum = nums[i] + nums[leftPtr] + nums[rightPtr];

                if (sum < 0) {
                    leftPtr++;
                } else if (sum > 0) {
                    rightPtr--;
                } else if (sum == 0) {
                    vector<int> answer;
                    answer.push_back(nums[i]);
                    answer.push_back(nums[leftPtr]);
                    answer.push_back(nums[rightPtr]);
                    result.emplace_back(answer);

                    while (leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr + 1]) {
                        leftPtr++;
                    }
                    while (leftPtr < rightPtr && nums[rightPtr] == nums[rightPtr - 1]) {
                        rightPtr--;
                    }

                    leftPtr++;
                    rightPtr--;
                }
            }

            last = nums[i];
        }
        return result;
    }
};