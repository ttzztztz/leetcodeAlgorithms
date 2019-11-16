class Solution {
public:
    int N, T;
    int dfs(const vector<vector<int>>& clips, vector<vector<int>>& dp, int index, int end) {
        if (end >= T) {
            return 0;
        }
        if (index > N) {
            return 999999;
        }

        if (dp[index][end] != -1) {
            return dp[index][end];
        }

        int answer = 999999;
        for (int i = index; i < N; i++) {
            const int _start = clips[i][0], _end = clips[i][1];
            if (_start <= end) {
                answer = min(answer, 1 + dfs(clips, dp, i + 1, _end));
            }

            if (_start > end) {
                break;
            }
        }
        return dp[index][end] = answer;
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        N = clips.size(), this->T = T;

        vector<vector<int>> dp(105, vector<int>(105, -1));
        sort(clips.begin(), clips.end(), [](const vector<int>& $1, const vector<int>& $2)->bool{
            return $1[0] < $2[0];
        });

        const int answer = dfs(clips, dp, 0, 0);
        return answer == 999999 ? -1 : answer;
    }
};