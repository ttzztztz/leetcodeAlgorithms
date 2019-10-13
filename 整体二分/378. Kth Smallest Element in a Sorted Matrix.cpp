class Solution {
public:
    int N, M;
    int solve(vector<vector<int>>& matrix, int k) {
        int answer = 0;
        for (int i = 0; i < N; i++) {
            auto it = std::upper_bound(matrix[i].begin(), matrix[i].end(), k);
            answer += it - matrix[i].begin();
        }
        return answer;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        N = matrix.size(), M = matrix[0].size();

        long long left = matrix[0][0], right = matrix[N - 1][M - 1];
        while (left <= right) {
            long long middle = (left + right) >> 1;

            if (solve(matrix, middle) >= k) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return right + 1;
    }
};