class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        const int n = heights.size();
        
        vector<int> l(n, 0), r(n, 0), stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) stk.pop_back();

            if (stk.empty()) l[i] = -1;
            else l[i] = stk.back();

            stk.push_back(i);
        }

        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) stk.pop_back();

            if (stk.empty()) r[i] = n;
            else r[i] = stk.back();

            stk.push_back(i);
        }
 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (r[i] - l[i] - 1));
        }
        return ans;
    }
};