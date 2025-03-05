class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_val = numeric_limits<int>::max();
        const int n = prices.size();
        for (int i = 0; i < n; i++) {
            if (i >= 1) {
                ans = max(ans, prices[i] - min_val);
            }
            min_val = min(min_val, prices[i]);
        }
        return ans;
    }
};