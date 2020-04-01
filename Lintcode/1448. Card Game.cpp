class Solution {
public:
    /**
     * @param n: The number of cards
     * @param totalProfit: The totalProfit
     * @param totalCost: The totalCost
     * @param a: The profit of cards
     * @param b: The cost of cards
     * @return: Return the number of legal plan
     */
    int numOfPlan(int n, int totalProfit, int totalCost, vector<int> &a, vector<int> &b) {
        vector<vector<int>> f(totalCost + 5, vector<int>(totalProfit + 5));
        f[0][0] = 1;
        const int MOD = 1e9+7;
        
        for (int i = 0; i < n; i++) {
            for (int j = totalCost + 1; j >= 0; j--) {
                for (int k = totalProfit + 1; k >= 0; k--) {
                    const int nextJ = min(totalCost + 1, j + b[i]);
                    const int nextK = min(totalProfit + 1, k + a[i]);
                    
                    f[nextJ][nextK] += f[j][k];
                    f[nextJ][nextK] %= MOD;
                }
            }
        }
        
        long long answer = 0;
        for (int i = 0; i < totalCost; i++) {
            answer += f[i][totalProfit + 1];
            answer %= MOD;
        }
        return answer;
    }
};
