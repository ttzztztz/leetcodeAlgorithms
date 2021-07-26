class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int n = heights.size();
        vector<int> ans(n, 0), stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] > heights[stk.back()]) {
                stk.pop_back();
                ans[i]++;
            }
            
            if (!stk.empty()) ans[i]++;
            stk.push_back(i);
        }
        return ans;
    }
};