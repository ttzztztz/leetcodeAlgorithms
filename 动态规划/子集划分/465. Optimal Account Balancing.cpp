class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (auto& v : transactions) {
            balance[v[0]] -= v[2];
            balance[v[1]] += v[2];
        }
        
        vector<int> nums;
        for (auto [k, v] : balance) {
            if (v != 0) nums.push_back(v);
        }
        
        const int n = nums.size();
        vector<int> dp(1 << n, 0), sum(1 << n, 0);
        for (int state = 1; state < (1 << n); state++) {
            for (int i = 0; i < n; i++) {
                if (!(state & (1 << i))) continue;
                
                sum[state] = sum[state ^ (1 << i)] + nums[i];
                if (sum[state] == 0) {
                    dp[state] = max(dp[state], dp[state ^ (1 << i)] + 1);
                } else {
                    dp[state] = max(dp[state], dp[state ^ (1 << i)]);
                }
            }
        }
        
        return n - dp[(1 << n) - 1];
    }
};
