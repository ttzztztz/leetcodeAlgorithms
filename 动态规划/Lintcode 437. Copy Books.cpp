class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        const int n = pages.size();
        vector<vector<int>> memo(k + 1, vector<int>(n + 1, numeric_limits<int>::max()));
        
        vector<int> prefix_sum = {0};
        for (int i = 0; i < n; i++) prefix_sum.push_back(prefix_sum.back() + pages[i]);
        
        for (int i = 0; i <= n; i++) {
            memo[1][i] = prefix_sum[i];
        }
        
        for (int i = 2; i <= k; i++) {
            for (int j = 0; j <= n; j++) {
                memo[i][j] = min(memo[i][j], memo[i - 1][j]);
                for (int k = 0; k + 1 <= j; k++) {
                    memo[i][j] = min(memo[i][j], max(prefix_sum[j] - prefix_sum[k], memo[i - 1][k]));
                }
            }
        }
        
        return memo[k][n];
    }
};
