class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        if (heights.empty()) return {};

        const int n = heights.size();
        vector<int> ans = {n - 1};
        int max_height = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (heights[i] > max_height) ans.push_back(i);
            max_height = max(max_height, heights[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
