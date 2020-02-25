class Solution {
public:
    /**
     * @param matrix: a 2D matrix
     * @param k: an integer
     * @return: the max sum of a rectangle in the matrix such that its sum is no larger than k
     */
    int maxSumSubmatrix(vector<vector<int>> &matrix, int K) {
        const int N = matrix.size(), M = matrix[0].size();
        
        vector<vector<int>> f(N + 1, vector<int>(M + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                f[i][j] = f[i][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        int answer = numeric_limits<int>::min();
        for (int i = 0; i <= M; i++) {
            for (int j = i + 1; j <= M; j++) {
                set<int> g;
                int Sj = 0;
                
                for (int k = 0; k <= N; k++) {
                    const int now = f[k][j] - f[k][i];
                    Sj += now;
                    
                    auto it = g.lower_bound(Sj - K);
                    if (it != g.end()) answer = max(answer, Sj - (*it));
                    
                    g.insert(Sj);
                }
            }
        }
        
        return answer;
    }
};
