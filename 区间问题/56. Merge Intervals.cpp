class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (0 == intervals.size()) {
            return vector<vector<int>>();
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int>& $1, const vector<int>& $2)->bool{
            if ($1[0] == $2[0]) {
                return $1[1] < $2[1];
            } else {
                return $1[0] < $2[0];
            }
        });

        vector<vector<int>> answer;
        int previousStart = intervals[0][0], previousEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            const vector<int>& interval = intervals[i];

            if (interval[0] <= previousEnd) {
                previousStart = std::min(interval[0], previousStart);
                previousEnd = std::max(interval[1], previousEnd);
            } else {
                vector<int> pair = {previousStart, previousEnd};
                answer.push_back(pair);

                previousStart = interval[0];
                previousEnd = interval[1];
            }
        }

        vector<int> pair = {previousStart, previousEnd};
        answer.push_back(pair);

        return answer;
    }
};