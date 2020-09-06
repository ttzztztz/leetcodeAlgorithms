class Solution {
public:
    int dp[15][305];
    int dfs(const vector<int>& jobDifficulty, const int d, int day, int i) {
        if (day == d) {
            return i == jobDifficulty.size() ? 0 : 123456;
        }
        if (i >= jobDifficulty.size()) {
            return day == d ? 0 : 123456;
        }
        
        if (dp[day][i] != -1) {
            return dp[day][i];
        }
        
        int answer = 123456;
        const int N = jobDifficulty.size();
        int current = jobDifficulty[i];
        for (int j = i + 1; j <= N; j++) {
            answer = min(answer, current + dfs(jobDifficulty, d, day + 1, j));
            if (j < N) current = max(current, jobDifficulty[j]);
        }
        return dp[day][i] = answer;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, 0xff, sizeof(dp));
        int answer = dfs(jobDifficulty, d, 0, 0);
        if (answer < 123456) {
            return answer;
        } else {
            return -1;
        }
    }
};
