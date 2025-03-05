class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            while (i + 1 < intervals.size() && max(l, intervals[i + 1][0]) <= min(r, intervals[i + 1][1])) {
                l = min(l, intervals[i + 1][0]);
                r = max(r, intervals[i + 1][1]);
                i++;
            }

            ans.push_back(vector<int>{ l, r });
        }
        return ans;
    }
};