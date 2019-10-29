class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int N = matrix.size(), M = matrix[0].size();
        vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                sum[i][j] = sum[i][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int answer = 0;
        for (int leftCol = 1; leftCol <= M; leftCol++) {
            for (int rightCol = leftCol; rightCol <= M; rightCol++) {
                unordered_map<int, int> sumMap;

                sumMap[0] = 1;
                int currentSum = 0;
                for (int row = 1; row <= N; row++) {
                    currentSum += sum[row][rightCol] - sum[row][leftCol - 1];
                    answer += sumMap[currentSum - target];
                    sumMap[currentSum]++;
                }

            }
        }

        return answer;
    }
};