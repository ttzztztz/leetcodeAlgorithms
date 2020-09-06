class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        if (N == 0) return 0;
        vector<int> left(N, 0), right(N, 0);
        
        vector<int> stack;
        for (int i = 0; i < N; i++) {
            while (stack.size() && heights[stack.back()] >= heights[i]) {
                stack.pop_back();
            }
            
            if (stack.size()) {
                left[i] = stack.back();
            } else {
                left[i] = -1;
            }
            stack.push_back(i);
        }
        
        stack.clear();
        for (int i = N - 1; i >= 0; i--) {
            while (stack.size() && heights[stack.back()] >= heights[i]) {
                stack.pop_back();
            }
            
            if (stack.size()) {
                right[i] = stack.back();
            } else {
                right[i] = N;
            }
            stack.push_back(i);
        }
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            answer = max(answer, heights[i] * (right[i] - left[i] - 1));
        }
        return answer;
    }
};
