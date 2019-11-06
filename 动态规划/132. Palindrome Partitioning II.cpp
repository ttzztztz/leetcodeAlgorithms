class Solution {
public:
    int N;
    bool judge(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }
    int dfs(vector<int>& dp, const string& s, int index) {
        if (index == N) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        int answer = 99999999;
        for (int i = index; i < N; i++) {
            if (judge(s, index, i)) {
                answer = min(answer, 1 + dfs(dp, s, i + 1));
            }
        }
        return dp[index] = answer;
    }
    int minCut(string s) {
        N = s.size();
        vector<int> dp(N + 5, -1);

        return dfs(dp, s, 0) - 1;
    }
};