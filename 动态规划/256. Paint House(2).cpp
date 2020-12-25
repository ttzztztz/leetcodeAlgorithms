class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        const int n = costs.size();
        vector<int> dp = costs[0];
        for (int i = 1; i < n; i++) {
            vector<int> dp_next(3, numeric_limits<int>::max());
            
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    
                    dp_next[j] = min(dp_next[j], dp[k] + costs[i][j]);
                }
            }
            dp = dp_next;
        }
        
        return min(min(dp[0], dp[1]), dp[2]);
    }
};
