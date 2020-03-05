class Solution {
public:
    /**
     * @param target: 
     * @return: return a integer
     */
    int racecar(int target) {
        dp = vector<int>(target + 5, -1);
        return dfs(target);
    }
private:
    vector<int> dp;
    int dfs(int target) {
        if (target == 0) return 0;
        if (dp[target] != -1) return dp[target];
        
        const int n = floor(log2(target + 1));
        if ((1 << n) == target + 1) return dp[target] = n;
        
        int answer = dfs((1 << (n + 1)) - 1 - target) + n + 2;
        for (int b = 0; b < n; b++) {
            answer = min(answer, dfs(target - (1 << n) + (1 << b)) + n + b + 2);
        }
        
        return dp[target] = answer;
    }
};
