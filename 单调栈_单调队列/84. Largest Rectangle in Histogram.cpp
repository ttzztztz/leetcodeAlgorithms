class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        int answer = 0, N = heights.size();
        vector<int> stack;
        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[stack.back()] > heights[i]) {
                int lastIndex = stack.back();
                int lastHeight = heights[lastIndex];
                stack.pop_back();

                int width = stack.empty() ? i : (i - stack.back() - 1);
                int square = lastHeight * width;
                answer = std::max(answer, square);
            }
            stack.push_back(i);
        }

        while (!stack.empty()) {
            int lastIndex = stack.back();
            int lastHeight = heights[lastIndex];
            stack.pop_back();
            int width = stack.empty() ? N : (N - stack.back() - 1);

            int square = lastHeight * width;
            answer = std::max(answer, square);
        }
        return answer;
    }
};