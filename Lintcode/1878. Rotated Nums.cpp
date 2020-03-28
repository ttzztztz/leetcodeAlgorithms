class Solution {
public:
    /**
     * @param n: length of good nums
     * @return: The num of good nums of length n
     */
    long long RotatedNums(int n) {
        if (n == 1) return 5;
        
        if (n % 2 == 1) {
            return 6 * 5 * dfs((n / 2) - 1);
        } else {
            return 6 * dfs((n / 2) - 1);
        }
    }
private:
    long long dfs(int n) {
        if (n == 0) return 1;
        return 7 * dfs(n - 1);
    }
};
