class Solution {
public:
    int trap(vector<int>& height) {
        if (0 == height.size()) {
            return 0;
        }
        int answer = 0;

        int leftMax[height.size() + 1], rightMax[height.size() + 1];
        std::memset(leftMax, 0, sizeof(leftMax));
        std::memset(rightMax, 0, sizeof(rightMax));

        leftMax[height.size() - 1] = height[height.size() - 1];
        for (int j = height.size() - 2; j >= 0; j--) {
            leftMax[j] = std::max(leftMax[j + 1], height[j]);
        }
        rightMax[0] = height[0];
        for (int j = 1; j < height.size(); j++) {
            rightMax[j] = std::max(rightMax[j - 1], height[j]);
        }

        for (int i = 0; i < height.size(); i++) {
            const int h = height[i];
            answer += std::min(leftMax[i], rightMax[i]) - h;
        }

        return answer;
    }
};