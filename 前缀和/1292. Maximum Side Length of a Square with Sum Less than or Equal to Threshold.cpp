class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int N = mat.size(), M = mat[0].size();
        vector<vector<int>> prefixSum(N + 1, vector<int>(M + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                prefixSum[i][j] = mat[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                prefixSum[i][j] += prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1];
            }
        }

        int answer = 0;
        for (int side = min(N, M); side >= 1; side--) {
            bool find = false;

            for (int i = 0; i + side <= N; i++) {
                for (int j = 0; j + side <= M; j++) {
                    const int sum = prefixSum[i + side][j + side] - prefixSum[i][j + side] - prefixSum[i + side][j] + prefixSum[i][j];
                    if (sum <= threshold) {
                        find = true;
                        break;
                    }
                }

                if (find) {
                    break;
                }
            }

            if (find) {
                return side;
            }
        }
        return answer;
    }
};