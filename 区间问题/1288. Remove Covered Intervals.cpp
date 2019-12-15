class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        vector<bool> removed(N + 5, false);
        int rest = 0;

        for (int i = 0; i < N; i++) {
            if (removed[i]) continue;

            for (int j = i + 1; j < N; j++) {
                if (removed[j]) continue;
                if (removed[i]) break;

                if (intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1]) {
                    rest++;
                    removed[j] = true;
                } else if (intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]) {
                    rest++;
                    removed[i] = true;
                }
            }
        }

        return N - rest;
    }
};