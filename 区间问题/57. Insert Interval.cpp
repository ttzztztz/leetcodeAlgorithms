class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int n = intervals.size();
        vector<vector<int>> ans;
        int l = newInterval[0], r = newInterval[1];
        int ptr = 0;

        while (ptr < n && intervals[ptr][1] < l) {
            ans.push_back(intervals[ptr]);
            ptr++;
        }

        while (ptr < n && max(intervals[ptr][0], l) <= min(intervals[ptr][1], r)) {
            l = min(l, intervals[ptr][0]);
            r = max(r, intervals[ptr][1]);
            ptr++;
        }

        ans.push_back(vector<int>{ l, r });

        while (ptr < n && r < intervals[ptr][0]) {
            ans.push_back(intervals[ptr]);
            ptr++;
        }
        return ans;
    }
};