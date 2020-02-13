class Solution {
public:
    /**
     * @param A: a list of integer
     * @param B: an integer
     * @return: return a list of integer
     */
    vector<int> cheapestJump(vector<int> &A, int B) {
        const int N = A.size();
        this->B = B;
        
        dp = vector<int>(N + 1, 9999999);
        
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            if (dp[i] >= 9999999) continue;
            for (int j = i + 1; j < N && j <= i + B; j++) {
                if (A[j] == -1) continue;
                dp[j] = min(dp[j], dp[i] + A[j]);
            }
        }
        
        if (dp[N - 1] >= 9999999) return vector<int>{};
        answer.push_back(1);
        findAnswer = false;
        dfs(A, 0);
        return answer;
    }
private:
    int B;
    vector<int> dp;
    vector<int> answer;
    bool findAnswer;
    void dfs(const vector<int> &A, int u) {
        const int N = A.size();
        
        if (u == N - 1) {
            findAnswer = true;
            return;
        }
        
        for (int j = u + 1; j < N && j <= u + B; j++) {
            if (A[j] == -1) continue;
            if (dp[j] == dp[u] + A[j]) {
                answer.push_back(j + 1);
                dfs(A, j);
                if (findAnswer) return;
                answer.pop_back();
            }
        }
    }
};
