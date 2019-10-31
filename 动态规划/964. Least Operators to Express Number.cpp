class Solution {
public:
    int x;

    int cost(int i) {
        if (i == 0) {
            return 2;
        } else {
            return i;
        }
    }

    int dfs(map<pair<int, int>, int>& dp, int i, int target) {
        pair<int, int> key = std::make_pair(i, target);

        if (dp.count(key)) {
            return dp[key];
        }
        if (target == 0) {
            return 0;
        } else if (target == 1) {
            return cost(i);
        } else if (i >= 39) {
            return 99999999;
        }

        int answer = 0;
        const int mod = target % x;
        const int next = target / x;

        answer = std::min(
                mod * cost(i) + dfs(dp, i + 1, next),
                (x - mod) * cost(i) + dfs(dp, i + 1, next + 1)
        );

        return dp[key] = answer;
    }

    int leastOpsExpressTarget(int x, int target) {
        this->x = x;
        map<pair<int, int>, int> dp;

        return dfs(dp, 0, target) - 1;
    }
};