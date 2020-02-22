class Solution {
public:
    /**
     * @param m: a integer
     * @param n: a integer
     * @param k: a integer
     * @return: return a integer
     */
    int solve(int m, int n, int k) {
        int answer = 0;
        for (int i = 1; i <= m; i++) {
            answer += min(k / i, n);
        }
        return answer;
    }
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left <= right) {
            const int mid = (left + right) >> 1;
            if (solve(m, n, mid) >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
