class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<long long> dp(505, 0);

        dp[0] = startFuel;
        for (int i = 0; i < stations.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = std::max(dp[j + 1], stations[i][1] + dp[j]);
                }
            }
        }

        for (int i = 0; i <= stations.size(); i++) {
            if (dp[i] >= target) {
                return i;
            }
        }

        return -1;
    }
};