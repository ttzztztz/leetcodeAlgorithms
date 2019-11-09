class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        const int N = s1.size(), M = s2.size();
        vector<vector<long long>> dp(N + 5, vector<long long>(35, 0));
        for (int i = 0; i < N; i++) {
            int ptr = i;
            for (int j = 0; j < M; j++) {
                int count = 1;

                while (s1[ptr] != s2[j]) {
                    count++;
                    if (count > N) {
                        return 0;
                    }
                    ptr = (ptr + 1) % N;
                }

                ptr = (ptr + 1) % N;
                dp[i][0] += count;
            }
        }

        long long answer = 0;
        for (int j = 1; j <= 30; j++) {
            for (int i = 0; i < N; i++) {
                dp[i][j] = dp[i][j - 1] + dp[(i + dp[i][j - 1]) % N][j - 1];
            }
        }

        for (int i = 0; i < N; i++) {
            long long temp = 0, state = i;
            for (int j = 30; j >= 0; j--) {
                if (state + dp[state % N][j] <= n1 * N) {
                    state += dp[state % N][j];
                    temp += 1 << j;
                }
            }
            answer = max(answer, temp);
        }
        return answer / n2;
    }
};