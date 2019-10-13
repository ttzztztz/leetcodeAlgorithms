class Solution {
public:
    int solve(vector<int>& nums, int k) {
        const int N = nums.size();
        int answer = 0;

        for (int leftPtr = 0, rightPtr = 0; leftPtr < N; leftPtr++) {
            while (rightPtr + 1 < N && nums[rightPtr + 1] - nums[leftPtr] <= k) {
                rightPtr++;
            }
            answer += rightPtr - leftPtr;
        }

        return answer;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int leftPtr = 0, rightPtr = nums.back() - nums.front();
        while (leftPtr <= rightPtr) {
            int middle = (leftPtr + rightPtr) >> 1;
            if (solve(nums, middle) >= k) {
                rightPtr = middle - 1;
            } else {
                leftPtr = middle + 1;
            }
        }
        return rightPtr + 1;
    }
};