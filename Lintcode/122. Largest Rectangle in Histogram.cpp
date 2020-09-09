class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        int answer = 0;
        const int n = height.size();
        
        vector<int> stk;
        vector<int> f(n, 0), g(n, 0);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[stk.back()] >= height[i]) stk.pop_back();
            if (stk.empty()) f[i] = -1;
            else f[i] = stk.back();
            stk.push_back(i);
        }
        
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && height[stk.back()] >= height[i]) stk.pop_back();
            if (stk.empty()) g[i] = n;
            else g[i] = stk.back();
            stk.push_back(i);
        }
        
        
        for (int i = 0; i < n; i++) {
            answer = max(answer, (g[i] - f[i] - 1) * height[i]);
        }
        return answer;
    }
};