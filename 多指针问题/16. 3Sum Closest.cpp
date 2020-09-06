class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int answer = 0, lastDistance = 0x7fffffff;
        for (int i = 0; i < nums.size(); i++) {
            int leftPtr = i + 1, rightPtr = nums.size() - 1;
            while (leftPtr < rightPtr) {
                int sum = nums[i] + nums[leftPtr] + nums[rightPtr];

                if (abs(sum - target) < lastDistance) {
                    lastDistance = abs(sum - target);
                    answer = sum;
                    if (lastDistance == 0) {
                        return answer;
                    }
                }

                if (sum > target) {
                    rightPtr--;
                } else {
                    leftPtr++;
                }
            }
        }

        return answer;
    }
};