class Solution {
public:
    int dp[380];
    int nextIndex(const vector<int>& days, int nowIndex, int add) {
        int nextDay = days[nowIndex] + add;
        while (nowIndex < days.size() && days[nowIndex] < nextDay) {
            nowIndex++;
        }
        return nowIndex;
    }
    int dfs(const vector<int>& costs, const vector<int>& days, int nowIndex) {
        if (nowIndex >= days.size()) {
            return 0;
        }

        int nowDay = days[nowIndex];
        if (dp[nowDay] != -1) {
            return dp[nowDay];
        }

        int answer = 0x7fffffff;
        // <- select 1
        answer = std::min(answer, dfs(costs, days, nextIndex(days, nowIndex, 1)) + costs[0]);
        // <- select 7
        answer = std::min(answer, dfs(costs, days, nextIndex(days, nowIndex, 7)) + costs[1]);
        // <- select 30
        answer = std::min(answer, dfs(costs, days, nextIndex(days, nowIndex, 30)) + costs[2]);

        return dp[nowDay] = answer;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if (days.size() == 0) {
            return 0;
        }
        std::memset(dp, 0xff, sizeof(dp));
        return dfs(costs, days, 0);
    }
};