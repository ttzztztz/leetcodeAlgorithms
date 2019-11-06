class Solution {
public:
    int memo[32768];
    int dfs(int target) {
        if (memo[target] != -1) {
            return memo[target];
        }
        int answer = 9999999;
        const int div = ceil(log2(target + 1));
        if ((1 << div) == target + 1) {
            return memo[target] = div;
        }
        answer = min(answer, div + 1 + dfs((1 << div) - 1 - target));
        for (int m = 0; m < div - 1; m++) {
            answer = min(answer, div + m + 1 + dfs(target - (1 << (div - 1)) + (1 << m)));
        }
        return memo[target] = answer;
    }
    int racecar(int target) {
        memset(memo, 0xff, sizeof(memo));
        return dfs(target);
    }
};