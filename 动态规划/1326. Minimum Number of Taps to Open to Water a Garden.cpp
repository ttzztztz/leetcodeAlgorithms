class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int N = ranges.size();
        vector<vector<int>> range;
        
        for (int i = 0; i < ranges.size(); i++) {
            range.push_back(vector<int>{i - ranges[i], i + ranges[i]});
        }
        
        vector<int> dp(N + 5, N + 5);
        
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = min(n, range[i][1]); j >= max(0, range[i][0]); j--) {
                dp[j] = min(dp[j], dp[max(0, range[i][0])] + 1);
            }
        }
        
        if (dp[n] >= N + 5) {
            return -1;
        } else {
            return dp[n];
        }
    }
};
