class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (auto& t : transactions) {
            balance[t[0]] += t[2];
            balance[t[1]] -= t[2];
        }
        
        vector<int> nums;
        for (auto& [k, v] : balance) {
            if (v != 0) nums.push_back(v);
        }
        const int n = nums.size();

        vector<int> f(1 << n, 0), sum(1 << n, 0);
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum[i] += nums[j];
                }
            }
        }
        
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (sum[i] == 0) f[i] = max(f[i], f[i ^ (1 << j)] + 1);
                    else f[i] = max(f[i], f[i ^ (1 << j)]);
                }
            }
        }
        
        return n - f[(1 << n) - 1];
    }
};