class Solution {
public:
    int trap(vector<int>& height) {
        if (0 == height.size()) {
            return 0;
        }
        int answer = 0;

        int leftPtr = 0, rightPtr = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (leftPtr < rightPtr) {
            if (height[leftPtr] < height[rightPtr]) {
                leftMax = std::max(leftMax, height[leftPtr]);
                answer += leftMax - height[leftPtr];
                leftPtr++;
            } else {
                rightMax = std::max(rightMax, height[rightPtr]);
                answer += rightMax - height[rightPtr];
                rightPtr--;
            }
        }

        return answer;
    }
};