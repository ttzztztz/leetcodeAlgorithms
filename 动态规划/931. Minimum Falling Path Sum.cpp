class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.size() == 0) {
            return 0;
        } else if (A[0].size() == 1) {
            int answer = 0;
            for (int i = 0; i < A[0].size(); i++) {
                answer += A[0][i];
            }
            return answer;
        }

        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (j == 0) {
                    A[i][j] += std::min(A[i - 1][j], A[i - 1][j + 1]);
                } else if (j == A[i].size() - 1) {
                    A[i][j] += std::min(A[i - 1][j], A[i - 1][j - 1]);
                } else {
                    A[i][j] += std::min(std::min(A[i - 1][j - 1], A[i - 1][j]), A[i - 1][j + 1]);
                }
            }
        }


        int answer = 0x7fffffff;
        for (int i = 0; i < A[A.size() - 1].size(); i++) {
            answer = std::min(answer, A[A.size() - 1][i]);
        }
        return answer;
    }
};