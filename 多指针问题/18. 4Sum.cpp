class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        std::sort(nums.begin(), nums.end());

        for (int _ = 0; _ < nums.size(); _++) {
            if (_ >= 1 && nums[_] == nums[_ - 1]) {
                continue;
            }
            int currentTarget = target - nums[_];
            for (int i = _ + 1; i < nums.size(); i++) {
                if (i > _ + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int leftPtr = i + 1, rightPtr = nums.size() - 1;
                while (leftPtr < rightPtr) {
                    int sum = nums[leftPtr] + nums[rightPtr] + nums[i];
                    if (sum == currentTarget) {
                        vector<int> oneAnswer = {nums[_], nums[i], nums[leftPtr], nums[rightPtr]};

                        while (leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr + 1]) {
                            leftPtr++;
                        }
                        while (leftPtr < rightPtr && nums[rightPtr] == nums[rightPtr - 1]) {
                            rightPtr--;
                        }

                        leftPtr++;
                        rightPtr--;
                        answer.push_back(oneAnswer);
                    } else if (sum < currentTarget) {
                        leftPtr++;
                    } else {
                        rightPtr--;
                    }

                }
            }
        }

        return answer;
    }
};