class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = intervals[i][0], r = intervals[i][1];
            while (i + 1 < intervals.size() && max(l, intervals[i + 1][0]) < min(r, intervals[i + 1][1])) {
                l = min(l, intervals[i + 1][0]);
                r = min(r, intervals[i + 1][1]);
                i++;
            }

            ans++;
        }
        return n - ans;
    }
};