class Solution {
public:
    /**
     * @param n: the number of people
     * @param m: the number of groups
     * @return: the number of grouping options
     */
    long long groupingOptions(int n, int m) {
        memset(f, 0xff, sizeof(f));
        return dfs(m, n - m);
    }
private:
    long long f[201][201];
    
    long long dfs(int group, int remain) {
        if (remain < 0) return 0;
        if (group == 0) {
            return (remain == 0) ? 1 : 0;
        }

        if (f[group][remain] != -1) return f[group][remain];
        long long answer = 0;
        for (int k = 0; k <= (remain / group); k++) {
            answer += dfs(group - 1, remain - k * group);
        }
        return f[group][remain] = answer;
    }
};
