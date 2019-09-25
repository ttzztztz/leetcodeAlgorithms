class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;

        int leftPtr = 0, rightPtr = height.size() - 1;
        while (leftPtr < rightPtr) {
            answer = std::max(answer, std::min(height[leftPtr], height[rightPtr]) * (rightPtr - leftPtr));
            if (height[rightPtr] < height[leftPtr]) {
                rightPtr--;
            } else {
                leftPtr++;
            }
        }

        return answer;
    }
};