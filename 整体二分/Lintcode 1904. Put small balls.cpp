class Solution {
public:
    /**
     * @param n: the number of buckets
     * @param k: the maximum times of operations
     * @param A: the number of balls in each bucket
     * @param W: the maximum capacity of each bucket
     * @return: return the minimum square value of the maximum difference
     */
    int getAns(int n, int k, vector<int> &A, vector<int> &W) {
        int left = 0, right = 0;
        for (int i = 1; i < n; i++) {
            right = max(right, (A[i] - A[i - 1]) * (A[i] - A[i - 1]));
        }
        
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            if (solve(A, W, mid) <= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    int solve(const vector<int> &A, const vector<int> &W, const int dist) {
        memset(f, 0xff, sizeof f);

        int answer = 999999;
        for (int i = 0; i <= W[0]; i++) {
            answer = min(answer, abs(A[0] - i) + dfs(A, W, dist, 1, i));
        }

        return answer;
    }
    int f[105][105];
    int dfs(const vector<int> &A, const vector<int> &W, const int dist, int i, int last) {
        if (i == A.size()) return 0;
        if (f[i][last] != -1) return f[i][last];
        
        int answer = 999999;
        for (int k = 0; k <= W[i]; k++) {
            if ((last - k) * (last - k) > dist) continue;
            answer = min(answer, abs(A[i] - k) + dfs(A, W, dist, i + 1, k));
            
        }
        return f[i][last] = answer;
    }
};
