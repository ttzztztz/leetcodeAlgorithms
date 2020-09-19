class Solution {
public:
    /**
     * @param heights: Students height
     * @return: How many people are not where they should be
     */
    int orderCheck(vector<int> &heights) {
        // write your code here
        int ans = 0;
        vector<int> h = heights;
        sort(h.begin(), h.end());
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != h[i]) ans++;
        }
        return ans;
    }
};
