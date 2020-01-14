class Solution {
public:
    bool haveOverlap(const vector<int>& $1, const vector<int>& $2) {
        const int a = max($1[0], $2[0]), b = min($1[1], $2[1]);
        return a < b;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if (intervals.size() == 0) return 0;
        
        const int N = intervals.size();
        vector<int> dp(N + 5, 0);
        
        dp[0] = 1;
        int answer = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (!haveOverlap(intervals[i], intervals[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            answer = max(answer, dp[i]);
        }
        
        return N - answer;
    }
};
