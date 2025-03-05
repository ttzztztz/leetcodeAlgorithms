class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        
        vector<vector<int>> dp(N, vector<int>(2, 1));
        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                } else if (nums[i] < nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            answer = max(answer, max(dp[i][0], dp[i][1]));
        }
        
        return answer;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(2, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, max(dfs(nums, i, 0), dfs(nums, i, 1)));
        return ans;
    }
private:
    int n;
    vector<vector<int>> memo;

    int dfs(const vector<int>& nums, int i, int ord) {
        if (memo[i][ord] != -1) return memo[i][ord];

        int ans = 1;
        for (int j = i + 1; j < n; j++) {
            if (
                (ord == 0 && nums[i] < nums[j])
                || (ord == 1 && nums[i] > nums[j])
            ) {
                ans = max(ans, 1 + dfs(nums, j, ord ^ 1));
            }
        }
        return memo[i][ord] = ans;
    }
};
